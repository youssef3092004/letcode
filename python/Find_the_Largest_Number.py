def find_largest(numbers: list) -> int:
    maxe = numbers[0]
    for number in numbers:
        if number > maxe:
            maxe = number
    print(maxe)

def find_smallest(numbers: list) -> int:
    maxe = numbers[0]
    for number in numbers:
        if number < maxe:
            maxe = number
    print(maxe)

if __name__ == '__main__':
    find_largest([10, 24, 32, 47, 2, 19])
