#include<iostream>
#include<string>
using namespace std;

#define MAX_SIZE 5

template<class Type>
class Stack
{
    Type stack[MAX_SIZE];       // stack array
    int TOP;                    // top position

public:

    Stack()
    {
        TOP=-1;
    }

    void push(Type data)
    {
        cout<<"--------------------"<<endl;

        if(TOP==MAX_SIZE-1)
        {
            cout<<"Stack Overflow."<<endl;
        }
        else
        {
            TOP++;
            stack[TOP]=data;
            cout<<"Element pushed."<<endl;
        }

        cout<<"--------------------"<<endl;
    }

    void pop()
    {
        cout<<"--------------------"<<endl;

        if(TOP==-1)
        {
            cout<<"Stack Underflow."<<endl;
        }
        else
        {
            TOP--;
            cout<<"Element popped."<<endl;
        }

        cout<<"--------------------"<<endl;
    }

    void display()
    {
        cout<<"--------------------"<<endl;

        if(TOP==-1)
        {
            cout<<"Stack is Empty."<<endl;
        }
        else
        {
            cout<<"Stack elements:"<<endl;

            for(int i=TOP;i>=0;i--)
            {
                cout<<stack[i]<<" ";
            }

            cout<<endl;
        }

        cout<<"--------------------"<<endl;
    }
};


void intMenu(Stack<int> &is)
{
    int choice;                 // menu choice
    int data;                   // input data
    int count=0;                // wrong count

    while(1)
    {
        cout<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Integer Stack"<<endl;
        cout<<"--------------------"<<endl;

        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Main Menu"<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        if(choice<1 || choice>4)
        {
            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        count=0;

        switch(choice)
        {
            case 1:
                cout<<"Enter integer: ";
                cin>>data;
                is.push(data);
                break;

            case 2:
                is.pop();
                break;

            case 3:
                is.display();
                break;

            case 4:
                return;
        }
    }
}


void charMenu(Stack<char> &cs)
{
    int choice;                 // menu choice
    char data;                  // input data
    int count=0;                // wrong count

    while(1)
    {
        cout<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Character Stack"<<endl;
        cout<<"--------------------"<<endl;

        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Main Menu"<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        if(choice<1 || choice>4)
        {
            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        count=0;

        switch(choice)
        {
            case 1:
                cout<<"Enter character: ";
                cin>>data;
                cs.push(data);
                break;

            case 2:
                cs.pop();
                break;

            case 3:
                cs.display();
                break;

            case 4:
                return;
        }
    }
}


void floatMenu(Stack<float> &fs)
{
    int choice;                 // menu choice
    float data;                 // input data
    int count=0;                // wrong count

    while(1)
    {
        cout<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Float Stack"<<endl;
        cout<<"--------------------"<<endl;

        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Main Menu"<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        if(choice<1 || choice>4)
        {
            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        count=0;

        switch(choice)
        {
            case 1:
                cout<<"Enter float value: ";
                cin>>data;
                fs.push(data);
                break;

            case 2:
                fs.pop();
                break;

            case 3:
                fs.display();
                break;

            case 4:
                return;
        }
    }
}


void doubleMenu(Stack<double> &ds)
{
    int choice;                 // menu choice
    double data;                // input data
    int count=0;                // wrong count

    while(1)
    {
        cout<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Double Stack"<<endl;
        cout<<"--------------------"<<endl;

        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Main Menu"<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        if(choice<1 || choice>4)
        {
            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        count=0;

        switch(choice)
        {
            case 1:
                cout<<"Enter double value: ";
                cin>>data;
                ds.push(data);
                break;

            case 2:
                ds.pop();
                break;

            case 3:
                ds.display();
                break;

            case 4:
                return;
        }
    }
}


void stringMenu(Stack<string> &ss)
{
    int choice;                 // menu choice
    string data;                // input data
    int count=0;                // wrong count

    while(1)
    {
        cout<<endl;
        cout<<"--------------------"<<endl;
        cout<<"String Stack"<<endl;
        cout<<"--------------------"<<endl;

        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Main Menu"<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        if(choice<1 || choice>4)
        {
            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                exit(0);
            }

            continue;
        }

        count=0;

        switch(choice)
        {
            case 1:
                cout<<"Enter string: ";
                cin>>data;
                ss.push(data);
                break;

            case 2:
                ss.pop();
                break;

            case 3:
                ss.display();
                break;

            case 4:
                return;
        }
    }
}


int main()
{
    Stack<int> is;              // integer stack
    Stack<char> cs;             // character stack
    Stack<float> fs;            // float stack
    Stack<double> ds;           // double stack
    Stack<string> ss;           // string stack

    int ic=0;                   // integer created
    int cc=0;                   // character created
    int fc=0;                   // float created
    int dc=0;                   // double created
    int sc=0;                   // string created

    int choice;                 // menu choice
    int s;                      // old/new choice
    int count=0;                // wrong count

    while(1)
    {
        cout<<endl;
        cout<<"========================================"<<endl;
        cout<<"              MAIN MENU"<<endl;
        cout<<"========================================"<<endl;

        cout<<"1. Integer Stack"<<endl;
        cout<<"2. Character Stack"<<endl;
        cout<<"3. Float Stack"<<endl;
        cout<<"4. Double Stack"<<endl;
        cout<<"5. String Stack"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"----------------------------------------"<<endl;
        cout<<"Enter your choice: ";

        cin>>choice;

        cout<<"----------------------------------------"<<endl;


        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                break;
            }

            continue;
        }


        if(choice<1 || choice>6)
        {
            count++;

            cout<<"Invalid choice"<<endl;

            if(count==3)
            {
                cout<<"Three consecutive invalid choices."<<endl;
                cout<<"Program terminated."<<endl;
                break;
            }

            continue;
        }


        count=0;


        if(choice==6)
        {
            cout<<"Program terminated."<<endl;
            break;
        }


        switch(choice)
        {
            case 1:

                if(ic==0)
                {
                    ic=1;
                    intMenu(is);
                }
                else
                {
                    cout<<"--------------------"<<endl;
                    cout<<"Integer stack already exists"<<endl;
                    cout<<"1. Continue old stack"<<endl;
                    cout<<"2. Create new stack"<<endl;
                    cout<<"Enter choice: ";
                    cin>>s;
                    cout<<"--------------------"<<endl;

                    if(s==1)
                    {
                        intMenu(is);
                    }
                    else if(s==2)
                    {
                        is=Stack<int>();
                        intMenu(is);
                    }
                    else
                    {
                        cout<<"Invalid choice"<<endl;
                    }
                }

                break;


            case 2:

                if(cc==0)
                {
                    cc=1;
                    charMenu(cs);
                }
                else
                {
                    cout<<"--------------------"<<endl;
                    cout<<"Character stack already exists"<<endl;
                    cout<<"1. Continue old stack"<<endl;
                    cout<<"2. Create new stack"<<endl;
                    cout<<"Enter choice: ";
                    cin>>s;
                    cout<<"--------------------"<<endl;

                    if(s==1)
                    {
                        charMenu(cs);
                    }
                    else if(s==2)
                    {
                        cs=Stack<char>();
                        charMenu(cs);
                    }
                    else
                    {
                        cout<<"Invalid choice"<<endl;
                    }
                }

                break;


            case 3:

                if(fc==0)
                {
                    fc=1;
                    floatMenu(fs);
                }
                else
                {
                    cout<<"--------------------"<<endl;
                    cout<<"Float stack already exists"<<endl;
                    cout<<"1. Continue old stack"<<endl;
                    cout<<"2. Create new stack"<<endl;
                    cout<<"Enter choice: ";
                    cin>>s;
                    cout<<"--------------------"<<endl;

                    if(s==1)
                    {
                        floatMenu(fs);
                    }
                    else if(s==2)
                    {
                        fs=Stack<float>();
                        floatMenu(fs);
                    }
                    else
                    {
                        cout<<"Invalid choice"<<endl;
                    }
                }

                break;


            case 4:

                if(dc==0)
                {
                    dc=1;
                    doubleMenu(ds);
                }
                else
                {
                    cout<<"--------------------"<<endl;
                    cout<<"Double stack already exists"<<endl;
                    cout<<"1. Continue old stack"<<endl;
                    cout<<"2. Create new stack"<<endl;
                    cout<<"Enter choice: ";
                    cin>>s;
                    cout<<"--------------------"<<endl;

                    if(s==1)
                    {
                        doubleMenu(ds);
                    }
                    else if(s==2)
                    {
                        ds=Stack<double>();
                        doubleMenu(ds);
                    }
                    else
                    {
                        cout<<"Invalid choice"<<endl;
                    }
                }

                break;


            case 5:

                if(sc==0)
                {
                    sc=1;
                    stringMenu(ss);
                }
                else
                {
                    cout<<"--------------------"<<endl;
                    cout<<"String stack already exists"<<endl;
                    cout<<"1. Continue old stack"<<endl;
                    cout<<"2. Create new stack"<<endl;
                    cout<<"Enter choice: ";
                    cin>>s;
                    cout<<"--------------------"<<endl;

                    if(s==1)
                    {
                        stringMenu(ss);
                    }
                    else if(s==2)
                    {
                        ss=Stack<string>();
                        stringMenu(ss);
                    }
                    else
                    {
                        cout<<"Invalid choice"<<endl;
                    }
                }

                break;
        }
    }

    return 0;
}
