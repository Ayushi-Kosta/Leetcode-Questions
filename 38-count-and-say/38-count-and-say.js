/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  let str = '1';

  for (let i = 2; i <= n; i += 1) {
    const arr = [];
    let start = 0;
    let current = start;

    while (current < str.length) {
      while (str[current] === str[start]) {
        current += 1;
      }

      arr.push(`${current - start}${str[start]}`);
      start = current;
    }

    str = arr.join('');
  }

  return str;
};