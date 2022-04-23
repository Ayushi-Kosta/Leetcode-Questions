class Solution {
public:
    map<string, string> m;
    long long a = 1;
    string s = to_string(a);
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[s]=longUrl;
        a++;
        string ans=s;
        s = to_string(a);
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));