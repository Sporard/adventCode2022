# coding: utf-8



def main():
    print('Starting the probleme')
    print('opening file')
    f = open('input.txt', 'r')
    array = []
    somme = 0
    for line in f:
        print(line)
        if line.strip():
            print(line)
            somme = somme + int(line)
        else:
            array.append(somme)
            somme = 0

    print('max is : ')
    print(max(array))

main()
