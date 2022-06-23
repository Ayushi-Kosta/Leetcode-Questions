/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  let str = '1';

  for (let i = 2; i <= n; i += 1) {
    const ans = [];
    let start = 0, current_string = start;

    while (current_string < str.length) {
      while (str[current_string] === str[start]) {
        current_string += 1;
      }

      ans.push(`${current_string - start}${str[start]}`);
      start = current_string;
    }

    str = ans.join('');
  }

  return str;
};