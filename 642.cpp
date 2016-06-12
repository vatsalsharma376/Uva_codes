    #include <bits/stdc++.h>
    using namespace std;
     
    int main ()
    {
        string dictionary [100 + 5];
        string scramble;
        string end = "XXXXXX";
     
        int dic_len = 0;
     
        while ( cin >> dictionary [dic_len] && dictionary [dic_len] != end ) dic_len++;
     
        sort (dictionary, dictionary + dic_len);
     
        while ( cin >> scramble && scramble != end ) {
            sort (scramble.begin (), scramble.end ());
            bool print_one = false;
            for ( int i = 0; i < dic_len; i++ ) {
                string temp = dictionary [i];
                sort (temp.begin (), temp.end ());
                if ( scramble == temp ) {
                    cout << dictionary [i] << endl;
                    print_one = true;
                }
            }
     
            if ( !print_one ) cout << "NOT A VALID WORD" << endl;
            cout << "******" << endl;
        }
     
        return 0;
    }
