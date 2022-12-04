# coding: utf-8



def part_1():
    print('Starting the probleme')
    print('opening file')
    f = open('input.txt', 'r')
    array = []
    somme = 0
    for line in f:
        print(line)
        if line.strip():
            somme = somme + int(line)
        else:
            array.append(somme)
            somme = 0

    print('max is : ')
    print(max(array))
    return array
def part_2(elves_list):
    print('begining of part 2 \n')
    maximum = []
    for i in range(0,3):
        maximum.append(max(elves_list))
        elves_list.pop(elves_list.index(max(elves_list)))
    print(maximum)
    print('sum of the calories')
    print(sum(maximum))

def main():
    elves_list = part_1()
    part_2(elves_list)

main()
