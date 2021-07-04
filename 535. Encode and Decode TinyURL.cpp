class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s;
        
        if(lts.find(longUrl) == lts.end()){
            do {
                for(int i = 0; i < lenCode; ++i){
                    s += ch[rand() % ch.size()];
                }
            } while(stl.find(s) != stl.end()); //To handle if the generated code is duplicate, keep generating
            lts[longUrl] = s;
            stl[s] = longUrl;
        } else {
            s = lts[longUrl];
        }
        
        return pre + s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string shortUrlCode = shortUrl.substr(19, 6);
        if(stl.find(shortUrlCode) != stl.end()){
            return stl[shortUrlCode];
        } else{
            return "";
        }

    }
    
private:
    string ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> lts, stl; //longToShort. ShortToLong
    string pre = "http://tinyurl.com/";
    int lenCode = 6;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));