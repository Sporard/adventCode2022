const fs = require("fs");
const events = require("events");
const readline = require("readline");
async function main() {
    console.log("start of day 3");
    fileStruct = createFileStruct('input.txt');
    processPart1(fileStruct);
    processPart2(fileStruct);
}
function createFileStruct(filename){
    const fileStream = fs.createReadStream(filename);
    const lineStream = readline.createInterface({
        input: fileStream
    });
    return {
        fileStream: fileStream,
        lineStream: lineStream
    }
}
// ----------------- PART 1 -----------------
async function processPart1 (fileStruct) {
    console.log("process part 1 ...");
    let sum = 0;
    fileStruct.lineStream.on('line', function (line){
        let length = line.length;
        let position = 0;
        if (length % 2 === 1){
            position = length / 2;
        } else {
            position = length / 2;
        }
        let firstHalf = line.slice(0, position);
        let secondHalf = line.slice(position, length);

        samePackages = findValuesPart1(firstHalf, secondHalf);
        sum += calculatePriorityPackages(samePackages);
    });

    await events.once(fileStruct.lineStream, 'close');
    console.log('The sum for part 1 is : ', sum);
}
function findValuesPart1(first, second){
    let res = [];
    for (char of first) {
        if (second.includes(char) && !res.includes(char)){
            res.push(char)
        } 
    }
    return res;
}

function calculatePriorityPackages(packages) {
    let sum = 0;
    for (package of packages){
        sum += calculatePriority(package);
    }
    return sum;
}

function calculatePriority(package) {
    // uppercase 
    if (package.charCodeAt(0) > 65 && package.charCodeAt(0) < 97){
        return (package.charCodeAt(0) - 64) + 26;
    } else {
        // lowercase
        if(package.charCodeAt(0) > 97) {
            return package.charCodeAt(0) - 96;
        }
    }
}
// ----------------- PART 2 -----------------
async function processPart2(fileStruct){
    console.log("process part 2 ...");
    let sum = 0;
    let i = 0;
    let elfGroupe = [];
    fileStruct.lineStream.on('line', function (line){
        elfGroupe.push(line);
        i++;
        if (i === 3){
            elfGroupBadge = findValuesPart2(elfGroupe);
            sum += calculatePriority(elfGroupBadge);
            i = 0;
            elfGroupe = [];
        }
        
    });

    await events.once(fileStruct.lineStream, 'close');
    console.log('The sum for part 2 is : ', sum);
}

function findValuesPart2(elfGroup){
    for (char of elfGroup[0]){
        if (elfGroup[1].includes(char) && elfGroup[2].includes(char)) return char;
    }
    throw 'No badge found';
}
main();