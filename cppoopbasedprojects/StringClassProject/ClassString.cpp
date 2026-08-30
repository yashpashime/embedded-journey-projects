
#include<iostream>
using namespace std;

class String
{
        char *s;

        public:

        String()
        {
                s=new char[1];
                s[0]='\0';
        }

        String(const char *p)
        {
                int len = 0;

                if(p == nullptr)
                {
                        s = new char[1];
                        s[0] = '\0';
                        return;
                }

                for(len=0; p[len]; len++);

                s = new char[len+1];

                int i;
                for(i=0; i<len; i++)
                        s[i] = p[i];

                s[i] = '\0';
        }

        String(const String& p)
        {
                int len=0,i;

                for(len=0;p.s[len];len++);

                s=new char[len+1];

                for(i=0;i<len;i++)
                {
                        s[i]=p.s[i];
                }

                s[i]='\0';
        }

        ~String()
        {
                delete []s;
        }

        String& operator =(const String& p)
        {
                int len;

                if(this == &p)
                        return *this;

                for(len=0; p.s[len]; len++);

                delete [] s;

                s = new char[len+1];

                int i;

                for(i=0; i<len; i++)
                        s[i] = p.s[i];

                s[i] = '\0';

                return *this;
        }

        String operator +(const String& t)
        {
                int l1=0,l2=0,l=0,i;

                for(l1=0;s[l1];l1++);

                for(l2=0;t.s[l2];l2++);

                l=l1+l2;

                char *temp = new char[l+1];

                for(i=0;i<l1;i++)
                {
                        temp[i]=s[i];
                }

                for(i=l1;i<l;i++)
                {
                        temp[i]=t.s[i-l1];
                }

                temp[i]='\0';

                String p(temp);

                delete []temp;

                return p;
        }

        char& operator [](int index)
        {
                return s[index];
        }


        bool operator >(const String& t) const
        {
                char *p,*q;

                p=s;
                q=t.s;

                while(*p && *q)
                {
                        if(*p>*q)
                                return 1;

                        if(*p<*q)
                                return 0;

                        p++;
                        q++;
                }

                if(*p && *q=='\0')
                {
                        return 1;
                }

                return 0;
        }


        bool operator <(const String& t) const
        {
                char *p,*q;

                p=s;
                q=t.s;

                while(*p && *q)
                {
                        if(*p>*q)
                                return 0;

                        if(*p<*q)
                                return 1;

                        p++;
                        q++;
                }

                if(*p=='\0' && *q!='\0')
                {
                        return 1;
                }

                return 0;
        }


        bool operator >=(const String& t) const
        {
                char *p,*q;

                p=s;
                q=t.s;

                while(*p && *q)
                {
                        if(*p>*q)
                                return 1;

                        if(*p<*q)
                                return 0;

                        p++;
                        q++;
                }

                if(*p && *q=='\0')
                        return 1;

                if(*p=='\0' && *q)
                        return 0;

                return 1;
        }


        bool operator <=(const String& t) const
        {
                char *p,*q;

                p=s;
                q=t.s;

                while(*p && *q)
                {
                        if(*p>*q)
                                return 0;

                        if(*p<*q)
                                return 1;

                        p++;
                        q++;
                }

                if(*p && *q=='\0')
                        return 0;

                if(*p=='\0' && *q)
                        return 1;

                return 1;
        }


        bool operator !=(const String& t) const
        {
                char *p,*q;

                p=s;
                q=t.s;

                while(*p && *q)
                {
                        if(*p!=*q)
                                return 1;

                        p++;
                        q++;
                }

                if(*p != *q)
                        return 1;

                return 0;
        }


        bool operator ==(const String& t) const
        {
                char *p,*q;

                p=s;
                q=t.s;

                while(*p && *q)
                {
                        if(*p!=*q)
                                return 0;

                        p++;
                        q++;
                }

                if(*p != *q)
                        return 0;

                return 1;
        }


        friend istream& operator >>(istream& in,String &m);
        friend ostream& operator <<(ostream& out,const String &n);

        friend void strcpy(String &p, const String &q);
        friend void strncpy(String &, const String &, int);
        friend int strcmp(const String &, const String &);
        friend int strncmp(const String &, const String &, int);
        friend void strcat(String &, const String &);
        friend void strncat(String &, const String &, int);
        friend void strrev(String &);
        friend void strupr(String &);
        friend void strlwr(String &);
        friend char* strchr(String &, char);
        friend char* strrchr(String &, char);
        friend char* strstr(String &, const char *);
        friend int strlen(const String &);

};


istream& operator >>(istream& in,String &m)
{
        in>>m.s;

        return in;
}


ostream& operator <<(ostream& out,const String &n)
{
        out<<n.s;

        return out;
}


void strcpy(String &p, const String &q)
{
        p=q;
}


void strncpy(String &p, const String &q, int n)
{
        delete []p.s;

        p.s=new char[n+1];

        int i;

        for(i=0;i<n && q.s[i]!='\0';i++)
                p.s[i]=q.s[i];

        p.s[i]='\0';
}


int strcmp(const String &p, const String &q)
{
        if(p>q)
                return 1;

        if(p==q)
                return 0;

        return -1;
}


int strncmp(const String &p, const String &q, int n)
{
        int i;

        for(i = 0; i < n; i++)
        {
                if(p.s[i] > q.s[i])
                        return 1;

                if(p.s[i] < q.s[i])
                        return -1;

                if(p.s[i] == '\0')
                        return 0;
        }

        return 0;
}


void strcat(String &p, const String &q)
{
        p=p+q;
}


void strncat(String &p, const String &q, int n)
{
        int l1=0,l2=0;

        while(p.s[l1])
                l1++;

        while(q.s[l2] && l2<n)
                l2++;

        char *temp=new char[l1+l2+1];

        int i;

        for(i=0;i<l1;i++)
                temp[i]=p.s[i];

        for(int j=0;j<l2;j++)
                temp[i+j]=q.s[j];

        temp[i+l2]='\0';

        delete []p.s;

        p.s=temp;
}


void strrev(String &p)
{
        char *a = p.s;
        char *b = p.s;

        if(p.s[0]=='\0')
                return;

        while(*b)
                b++;

        b--;

        while(a < b)
        {
                char temp = *a;

                *a = *b;
                *b = temp;

                a++;
                b--;
        }
}


void strupr(String &p)
{
        char *a = p.s;

        while(*a)
        {
                if(*a >= 'a' && *a <= 'z')
                        *a = *a - 32;

                a++;
        }
}


void strlwr(String &p)
{
        char *a = p.s;

        while(*a)
        {
                if(*a >= 'A' && *a <= 'Z')
                        *a = *a + 32;

                a++;
        }
}


char* strchr(String &p, char ch)
{
        char *a = p.s;

        while(*a)
        {
                if(*a == ch)
                        return a;

                a++;
        }

        if(ch == '\0')
                return a;

        return NULL;
}


char* strrchr(String &p, char ch)
{
        char *a = p.s;

        while(*a)
                a++;

        if(ch == '\0')
                return a;

        if(a == p.s)
                return NULL;

        a--;

        while(a >= p.s)
        {
                if(*a == ch)
                        return a;

                a--;
        }

        return NULL;
}


char* strstr(String &p, const char *t)
{
        int i, j;

        for(i = 0; p.s[i] != '\0'; i++)
        {
                for(j = 0; t[j] != '\0'; j++)
                {
                        if(p.s[i+j] != t[j])
                                break;
                }

                if(t[j] == '\0')
                        return &p.s[i];
        }

        return NULL;
}


int strlen(const String &p)
{
        char *a = p.s;

        int count = 0;

        while(*a)
        {
                count++;
                a++;
        }

        return count;
}
int main()
{
        int pass = 0;
        int fail = 0;

        cout << "==========================================" << endl;
        cout << "       STRING CLASS TESTING" << endl;
        cout << "==========================================" << endl;


        // --------------------------------------------------
        // 1. DEFAULT CONSTRUCTOR
        // --------------------------------------------------

        cout << "\n1. Default Constructor" << endl;

        String a;

        if(strlen(a) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 2. PARAMETERIZED CONSTRUCTOR
        // --------------------------------------------------

        cout << "\n2. Parameterized Constructor" << endl;

        String b("Hello");

        if(strcmp(b,String("Hello")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 3. NULL POINTER CONSTRUCTOR
        // --------------------------------------------------

        cout << "\n3. nullptr Constructor" << endl;

        String nullString(nullptr);

        if(strlen(nullString) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 4. COPY CONSTRUCTOR
        // --------------------------------------------------

        cout << "\n4. Copy Constructor" << endl;

        String c(b);

        if(strcmp(c,b) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 5. ASSIGNMENT OPERATOR
        // --------------------------------------------------

        cout << "\n5. Assignment Operator" << endl;

        String d;

        d = b;

        if(strcmp(d,b) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 6. SELF ASSIGNMENT
        // --------------------------------------------------

        cout << "\n6. Self Assignment" << endl;

        d = d;

        if(strcmp(d,String("Hello")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 7. + OPERATOR
        // --------------------------------------------------

        cout << "\n7. + Operator" << endl;

        String e("Hello ");
        String f("World");

        String g = e + f;

        if(strcmp(g,String("Hello World")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 8. [] OPERATOR
        // --------------------------------------------------

        cout << "\n8. [] Operator" << endl;

        String h("Hello");

        h[0] = 'Y';

        if(strcmp(h,String("Yello")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 9. > OPERATOR
        // --------------------------------------------------

        cout << "\n9. > Operator" << endl;

        String i("World");
        String j("Hello");

        if(i > j)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 10. < OPERATOR
        // --------------------------------------------------

        cout << "\n10. < Operator" << endl;

        if(j < i)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 11. >= OPERATOR
        // --------------------------------------------------

        cout << "\n11. >= Operator" << endl;

        if(i >= j && i >= i)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 12. <= OPERATOR
        // --------------------------------------------------

        cout << "\n12. <= Operator" << endl;

        if(j <= i && j <= j)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 13. != OPERATOR
        // --------------------------------------------------

        cout << "\n13. != Operator" << endl;

        if(i != j && !(i != i))
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 14. == OPERATOR
        // --------------------------------------------------

        cout << "\n14. == Operator" << endl;

        if(i == String("World") && !(i == j))
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 15. << OPERATOR
        // --------------------------------------------------

        cout << "\n15. << Operator" << endl;

        cout << "Output should be: World" << endl;
        cout << "Actual output: " << i << endl;


        // --------------------------------------------------
        // 16. strcpy
        // --------------------------------------------------

        cout << "\n16. strcpy" << endl;

        String k("ABC");
        String l("XYZ");

        strcpy(k,l);

        if(strcmp(k,String("XYZ")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 17. strncpy
        // --------------------------------------------------

        cout << "\n17. strncpy" << endl;

        String m("123456");

        strncpy(m,String("ABCDEFG"),3);

        if(strcmp(m,String("ABC")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 18. strcmp
        // --------------------------------------------------

        cout << "\n18. strcmp" << endl;

        String n1("Apple");
        String n2("Banana");
        String n3("Apple");

        if(strcmp(n1,n2) < 0 &&
           strcmp(n2,n1) > 0 &&
           strcmp(n1,n3) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 19. strncmp
        // --------------------------------------------------

        cout << "\n19. strncmp" << endl;

        String o1("HelloWorld");
        String o2("HelloThere");

        if(strncmp(o1,o2,5) == 0 &&
           strncmp(o1,o2,6) > 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 20. strcat
        // --------------------------------------------------

        cout << "\n20. strcat" << endl;

        String p("Hello");
        String q("World");

        strcat(p,q);

        if(strcmp(p,String("HelloWorld")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 21. strncat
        // --------------------------------------------------

        cout << "\n21. strncat" << endl;

        String r("Hello");

        strncat(r,String("World"),3);

        if(strcmp(r,String("HelloWor")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 22. strrev
        // --------------------------------------------------

        cout << "\n22. strrev" << endl;

        String s1("ABCDE");

        strrev(s1);

        if(strcmp(s1,String("EDCBA")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 23. strupr
        // --------------------------------------------------

        cout << "\n23. strupr" << endl;

        String s2("hello World");

        strupr(s2);

        if(strcmp(s2,String("HELLO WORLD")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 24. strlwr
        // --------------------------------------------------

        cout << "\n24. strlwr" << endl;

        String s3("HELLO World");

        strlwr(s3);

        if(strcmp(s3,String("hello world")) == 0)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 25. strchr
        // --------------------------------------------------

        cout << "\n25. strchr" << endl;

        String s4("Hello World");

        char *x = strchr(s4,'W');

        if(x != NULL && *x == 'W')
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 26. strchr - CHARACTER NOT FOUND
        // --------------------------------------------------

        cout << "\n26. strchr - Character Not Found" << endl;

        x = strchr(s4,'Z');

        if(x == NULL)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 27. strrchr
        // --------------------------------------------------

        cout << "\n27. strrchr" << endl;

        String s5("banana");

        char *y = strrchr(s5,'a');

        if(y != NULL && *y == 'a')
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 28. strrchr - CHARACTER NOT FOUND
        // --------------------------------------------------

        cout << "\n28. strrchr - Character Not Found" << endl;

        y = strrchr(s5,'z');

        if(y == NULL)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 29. strstr
        // --------------------------------------------------

        cout << "\n29. strstr" << endl;

        String s6("Hello World");

        char *z = strstr(s6,"World");

        if(z != NULL && *z == 'W')
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 30. strstr - STRING NOT FOUND
        // --------------------------------------------------

        cout << "\n30. strstr - String Not Found" << endl;

        z = strstr(s6,"XYZ");

        if(z == NULL)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // 31. strlen
        // --------------------------------------------------

        cout << "\n31. strlen" << endl;

        String s7("Embedded");

        if(strlen(s7) == 8)
        {
                cout << "PASS" << endl;
                pass++;
        }
        else
        {
                cout << "FAIL" << endl;
                fail++;
        }


        // --------------------------------------------------
        // FINAL RESULT
        // --------------------------------------------------

        cout << "\n==========================================" << endl;
        cout << "              FINAL RESULT" << endl;
        cout << "==========================================" << endl;

        cout << "Tests Passed : " << pass << endl;
        cout << "Tests Failed : " << fail << endl;

        if(fail == 0)
        {
                cout << "\nALL TESTS PASSED!" << endl;
        }
        else
        {
                cout << "\nSOME TESTS FAILED!" << endl;
        }

        cout << "==========================================" << endl;

        return 0;
}
