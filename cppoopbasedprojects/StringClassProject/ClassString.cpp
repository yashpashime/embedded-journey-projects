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
    int ch;

    do
    {
        cout << "\n1. Constructors\n";
        cout << "2. Assignment / Copy\n";
        cout << "3. Operators\n";
        cout << "4. String Functions\n";
        cout << "5. Search Functions\n";
        cout << "6. strlen\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
            {
                String a;
                String b("Hello");
                String c(nullptr);
                String d(b);

                if(strlen(a) == 0 &&
                   strcmp(b,String("Hello")) == 0 &&
                   strlen(c) == 0 &&
                   strcmp(b,d) == 0)
                    cout << "PASS\n";
                else
                    cout << "FAIL\n";

                break;
            }

            case 2:
            {
                String a("Hello");
                String b;

                b = a;

                a = a;

                if(a == b && b == String("Hello"))
                    cout << "PASS\n";
                else
                    cout << "FAIL\n";

                break;
            }

            case 3:
            {
                String a("Hello");
                String b(" World");

                String c = a + b;

                a[0] = 'Y';

                if(c == String("Hello World") &&
                   a == String("Yello") &&
                   String("World") > String("Hello") &&
                   String("Hello") < String("World") &&
                   String("Hello") <= String("Hello") &&
                   String("World") >= String("Hello") &&
                   String("Hello") != String("World"))
                    cout << "PASS\n";
                else
                    cout << "FAIL\n";

                break;
            }

            case 4:
            {
                String a("Hello");
                String b("World");

                strcpy(a,b);

                if(a == String("World"))
                {
                    strncpy(a,String("Embedded"),4);

                    if(a == String("Embe"))
                    {
                        strcat(a,String("Test"));

                        if(a == String("EmbeTest"))
                        {
                            strncat(a,String("12345"),2);

                            if(a == String("EmbeTest12"))
                            {
                                strrev(a);

                                if(a == String("21tseTebmE"))
                                {
                                    strupr(a);

                                    if(a == String("21TSETEBME"))
                                    {
                                        strlwr(a);

                                        if(a == String("21tsetebme"))
                                            cout << "PASS\n";
                                        else
                                            cout << "FAIL\n";
                                    }
                                    else
                                        cout << "FAIL\n";
                                }
                                else
                                    cout << "FAIL\n";
                            }
                            else
                                cout << "FAIL\n";
                        }
                        else
                            cout << "FAIL\n";
                    }
                    else
                        cout << "FAIL\n";
                }
                else
                    cout << "FAIL\n";

                break;
            }

            case 5:
            {
                String a("Hello World");

                char *p1 = strchr(a,'W');
                char *p2 = strrchr(a,'l');
                char *p3 = strstr(a,"World");

                if(p1 != NULL &&
                   *p1 == 'W' &&
                   p2 != NULL &&
                   *p2 == 'l' &&
                   p3 != NULL &&
                   *p3 == 'W' &&
                   strchr(a,'X') == NULL &&
                   strstr(a,"XYZ") == NULL)
                    cout << "PASS\n";
                else
                    cout << "FAIL\n";

                break;
            }

            case 6:
            {
                String a("Embedded");

                if(strlen(a) == 8)
                    cout << "PASS\n";
                else
                    cout << "FAIL\n";

                break;
            }

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(ch != 0);

    return 0;
}
