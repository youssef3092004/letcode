def find_largest(numbers: list) -> int:
    maxe = 0
    for number in numbers:
        if number > maxe:
            maxe = number
    print(maxe)

if __name__ == '__main__':
    find_largest([10, 24, 32, 47, 2, 19])
