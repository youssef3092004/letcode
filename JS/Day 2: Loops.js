function vowelsAndConsonants(s) {
    const x = ['a', 'e', 'i', 'o', 'u'];
        for (let i = 0; i < s.length; i++) {
        if (x.includes(s[i])) {
            console.log(s[i]);
        }
    }
    for (let j = 0; j < s.length; j++) {
        if (!x.includes(s[j])) {
            console.log(s[j]);
        }
    }
}

