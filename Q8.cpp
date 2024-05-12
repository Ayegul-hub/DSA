#include <iostream>
#include <vector>
using namespace std;

void genIpUtil(string s, int start, int partNum, string ip, vector<string>& ips) {
    if (start == s.size() && partNum == 4) {
        ips.push_back(ip);
        return;
    }

    if (start >= s.size() || partNum == 4) {
        return;
    }

    if (s[start] == '0') {
        genIpUtil(s, start + 1, partNum + 1, ip + (partNum == 3 ? "0" : "0."), ips);
        return;
    }

    for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
        string sub = s.substr(start, len);
        int num = stoi(sub);
        if (num >= 0 && num <= 255) {
            genIpUtil(s, start + len, partNum + 1, ip + sub + (partNum == 3 ? "" : "."), ips);
        }
    }
}

vector<string> genIp(string s) {
    vector<string> ips;
    genIpUtil(s, 0, 0, "", ips);
    return ips;
}

int main() {
    string s = "1111";
    vector<string> ips = genIp(s);

    if (ips.empty()) {
        cout << "-1" << endl;
    }
    else {
        for (string ip : ips) {
            cout << ip << " ";
        }
        cout << endl;
    }

    return 0;
}
