// #include <iostream>
// using namespace std;


// long long mod_pow(long long base, long long exp, long long mod) {
//     __int128 result = 1;
//     __int128 b = base % mod;

//     while (exp > 0) {
//         if (exp & 1)
//             result = (result * b) % mod;
//         b = (b * b) % mod;
//         exp >>= 1;
//     }

//     return (long long)result;
// }

// int main() {
//     long long n, e, d, ciphertext;
//     cin >> n >> e >> d >> ciphertext;

//     cout << mod_pow(ciphertext, d, n) << endl;

//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

// Multiply two strings (big integers)
string multiply(const string &a, const string &b) {
    int n = a.size();
    int m = b.size();
    string res(n + m, '0');
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = res[i + j + 1] - '0' + mul;
           
            res[i + j + 1] = (sum % 10) + '0';
            res[i + j] += sum / 10;
        }

    
    int start = 0;

    while (start < res.size() && res[start] == '0') {
        start++;
    }

    if (start == res.size()) {
        return "0";
    } else {
        return res.substr(start);
    }

}

string mod(const string &a, const string &mod) {
    string res = "0";
    for (char c : a) {
        res = multiply(res, "10");
        res[res.size() - 1] += (c - '0');


        while (res.size() > mod.size() || (res.size() == mod.size() && res > mod)) {
            int i = res.size() - 1; 
            int j = mod.size() - 1;
            int borrow = 0;

            while (j >= 0) {
                int sub = (res[i] - '0') - (mod[j] - '0') - borrow;
                
                if (sub < 0) {
                    sub += 10;
                    borrow = 1;
                } 
                else {
                    borrow = 0;
                }
                
                res[i] = sub + '0';
                --i, 
                --j;
            }

            while (i >= 0 && borrow) {
                int sub = (res[i] - '0') - borrow;

                if (sub < 0) {
                    sub += 10;
                    borrow = 1;
                }
                else {
                    borrow = 0;
                }

                res[i--] = sub + '0';
            }

            int k = 0;
            while (k < res.size() && res[k] == '0') {
                k++;
            }
            if (k == res.size()) {
                res = "0";
            } 
            else {
                res = res.substr(k);
            }

        }
    }
    return res;
}

string divideBy2(const string &a) {
    string result;
    int carry = 0;

    for (char c : a) {
        int num = carry * 10 + (c - '0');
        result += (num / 2) + '0';
        carry = num % 2;
    }

    int k = 0;

    while (k < result.size() && result[k] == '0') {
        k++;
    }

    if (k == result.size()) {
        return result = "0";
    } else {
        return result = result.substr(k);
    }


}

bool isOdd(const string &s) {
    return (s.back() - '0') % 2 != 0;
}

string mod_pow(string base, string exp, string modn) {
    string result = "1";
    base = mod(base, modn);

    while (exp != "0") {
        if (isOdd(exp)) {
            result = mod(multiply(result, base), modn);
        }
        exp = divideBy2(exp);
        base = mod(multiply(base, base), modn);
    }
    return result;
}

int main() {
    string n, e, d, ciphertext;
    cin >> n >> e >> d >> ciphertext;

    cout << mod_pow(ciphertext, d, n) << endl;
    return 0;
}
 