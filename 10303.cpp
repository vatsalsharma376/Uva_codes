#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int maxn = 700;///注意此值的设置要留意中间结果  
  
char numstr[maxn];///输入输出接口  
  
struct bign  
{  
    int len, s[maxn];  
  
    bign()  
    {  
        memset(s, 0, sizeof(s));  
        len = 1;  
    }  
  
    bign(int num)  
    {  
        *this = num;  
    }  
  
    bign(const char* num)  
    {  
        *this = num;  
    }  
  
    bign operator = (const int num)  
    {  
        char s[maxn];  
        sprintf(s, "%d", num);  
        *this = s;  
        return *this;  
    }  
  
    bign operator = (const char* num)  
    {  
        len = strlen(num);  
        for (int i = 0; i < len; i++) s[i] = num[len - i - 1] & 15;  
        return *this;  
    }  
  
    ///输出  
    const char* str() const  
    {  
        if (len)  
        {  
            for (int i = 0; i < len; i++)  
                numstr[i] = '0' + s[len - i - 1];  
            numstr[len] = '\0';  
        }  
        else strcpy(numstr, "0");  
        return numstr;  
    }  
  
    ///去前导零  
    void clean()  
    {  
        while (len > 1 && !s[len - 1]) len--;  
    }  
  
    ///加  
    bign operator + (const bign& b) const  
    {  
        bign c;  
        c.len = 0;  
        for (int i = 0, g = 0; g || i < max(len, b.len); i++)  
        {  
            int x = g;  
            if (i < len) x += s[i];  
            if (i < b.len) x += b.s[i];  
            c.s[c.len++] = x % 10;  
            g = x / 10;  
        }  
        return c;  
    }  
  
    ///减  
    bign operator - (const bign& b) const  
    {  
        bign c;  
        c.len = 0;  
        for (int i = 0, g = 0; i < len; i++)  
        {  
            int x = s[i] - g;  
            if (i < b.len) x -= b.s[i];  
            if (x >= 0) g = 0;  
            else  
            {  
                g = 1;  
                x += 10;  
            }  
            c.s[c.len++] = x;  
        }  
        c.clean();  
        return c;  
    }  
  
    ///乘  
    bign operator * (const bign& b) const  
    {  
        bign c;  
        c.len = len + b.len;  
        for (int i = 0; i < len; i++)  
            for (int j = 0; j < b.len; j++)  
                c.s[i + j] += s[i] * b.s[j];  
        for (int i = 0; i < c.len - 1; i++)  
        {  
            c.s[i + 1] += c.s[i] / 10;  
            c.s[i] %= 10;  
        }  
        c.clean();  
        return c;  
    }  
  
    ///除  
    bign operator / (const bign &b) const  
    {  
        bign ret, cur = 0;  
        ret.len = len;  
        for (int i = len - 1; i >= 0; i--)  
        {  
            cur = cur * 10;  
            cur.s[0] = s[i];  
            while (cur >= b)  
            {  
                cur -= b;  
                ret.s[i]++;  
            }  
        }  
        ret.clean();  
        return ret;  
    }  
  
    ///模、余  
    bign operator % (const bign &b) const  
    {  
        bign c = *this / b;  
        return *this - c * b;  
    }  
  
    bool operator < (const bign& b) const  
    {  
        if (len != b.len) return len < b.len;  
        for (int i = len - 1; i >= 0; i--)  
            if (s[i] != b.s[i]) return s[i] < b.s[i];  
        return false;  
    }  
  
    bool operator > (const bign& b) const  
    {  
        return b < *this;  
    }  
  
    bool operator <= (const bign& b) const  
    {  
        return !(b < *this);  
    }  
  
    bool operator >= (const bign &b) const  
    {  
        return !(*this < b);  
    }  
  
    bool operator == (const bign& b) const  
    {  
        return !(b < *this) && !(*this < b);  
    }  
  
    bool operator != (const bign &a) const  
    {  
        return *this > a || *this < a;  
    }  
  
    bign operator += (const bign &a)  
    {  
        *this = *this + a;  
        return *this;  
    }  
  
    bign operator -= (const bign &a)  
    {  
        *this = *this - a;  
        return *this;  
    }  
  
    bign operator *= (const bign &a)  
    {  
        *this = *this * a;  
        return *this;  
    }  
  
    bign operator /= (const bign &a)  
    {  
        *this = *this / a;  
        return *this;  
    }  
  
    bign operator %= (const bign &a)  
    {  
        *this = *this % a;  
        return *this;  
    }  
};  
  
bign c[1001] = {1};  
  
int main()  
{  
    bign i;  
    int ii;  
    for (i = 1, ii = 1; ii <= 1000; i = i + 1, ++ii)  
        c[ii] = c[ii - 1] * ((i * 4) - 2)  / (i + 1);  
    while (~scanf("%d", &ii))  
        puts(c[ii].str());  
    return 0;  
}  
