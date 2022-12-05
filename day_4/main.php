<?php

function main(): void{

    echo('Begining of part 4' . PHP_EOL);
    processPart1("input.txt");
    processPart2("input.txt");
}

function processPart1(string $filename):void {
    echo('Processing of part 1' . PHP_EOL);
    $res = 0;
    if ($file = fopen($filename, "r")){
        while(!feof($file)){
            $line = fgets($file);
            $explodeLine =  explode(",", $line);
            $assignment1 = $explodeLine[0];
            $assignment2 = $explodeLine[1];
            $rangesAssignment1 = explode("-", $assignment1);
            $rangesAssignment2 = explode("-", $assignment2);
        }
    }

    echo('Results for part 1 is : ' . $res . PHP_EOL);
}

function processPart2(string $filename):void {
    echo('Processing of part 2' . PHP_EOL);
}


main();
?>