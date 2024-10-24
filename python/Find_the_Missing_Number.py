def find_missing_number(numbers: list, n: int) -> int:
    sum = []
    for i in range(numbers[0], numbers[-1]):
        if i not in numbers:
            sum.append(i)
    print(*sum)
if __name__ == '__main__':
    find_missing_number([1, 4, 5, 6, 7, 8, 9, 10], 10)
