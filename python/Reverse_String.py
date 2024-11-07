


def reverse_string(s):
    if len(s) <= 1:
        return s
    else:
        return reverse_string(s[1:]) + s[0]

# ello + h
# llo + e + h
# lo + l + e + h
# o + l + l + e + h
# hello => olleh


print(reverse_string("hello"))
