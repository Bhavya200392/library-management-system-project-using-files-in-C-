#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string>  
#include<cstring>
using namespace std;
class library
{
    private:
    static vector<string> v1 ;
    static vector<int> v2 ;
    static vector<string> namedetails;
    static vector<string> id;
    string book_name;
    int book_qun;
    int input;
    int book;
    int index=0;
    int count=0;
    string name;
    string nameid;
    string genrate;
    
    int position;
    public:
    void function()
    {
        cout<<"\nHI ! WEL-COME TO MY LIBRARY "<<endl;
        cout<<"PRESS 1 FOR GETTING DETAILS FOR PARTICULAR BOOK"<<endl;
        cout<<"PRESS 2 FOR AVAILS BOOK IF AVAILABLE"<<endl;
        cout<<"PRESS 3 FOR RETURN BOOK"<<endl;
        cout<<"PRESS 4 FOR ADD A BOOK"<<endl;
        cin>>input;  

        if(input==1)
            {
                cout<<"Enter Book Name"<<endl;
                cin>>book_name;
                ifstream fin;
                int cl=0;
                string s;
                //FINDING BOOK OPEN FILE !!
                fin.open("Books.pdf",ios::in);
                while (fin.eof()!=1)
                {
                    fin>>s;
                    if(book_name==s)                  
                    {
                        cout<<"Book Is Available !"<<endl;
                        count++;
                        break;
                    }
                }
                fin.close();
                // CHECK HOW MUCH AMOUNT OF BOOK IS THEIR !!!;
                if(count==1)
                {
                //Find Index Of Book // 
                fin.open("Books.pdf",ios::in);
                while(fin.eof()!=1)
                {
                    fin>>s;
                    if(book_name==s)
                    {
                        index=index+1;
                        break;
                    }
                    else
                    {
                        index=index+1;
                    }
                }
                fin.close();
                //BOOK IS AVAILABLE SO FIND ITS QUANTITY;
                ifstream f;
                string line;
                f.open("Quantity.pdf");
                while(!f.eof())
                {
                cl++;
                getline(f,line);
                if(cl==index) break;
                }
                cout<<"The Total No of Quantity is "<<line<<endl;
                index=0;
                count=0;
                f.close();
                cl=0;
                //CLOSED IT   
                }
                //IF BOOK IS NOT THERE !!!
                else
                {
                    fin.open("Books.pdf",ios::in);
                    cout<<"..............Available Related Books Are............"<<endl;
                    while (fin.eof()==0)
                    {
                        fin>>s;
                        if(book_name[0]==s[0])                  
                        {
                        cout<<s<<endl;
                        cl++;
                        }
                    }
                    fin.close();
                    if(cl==0)
                    {
                        cout<<"Soory Book Is Not Available Will Update Soon !!!!";
                    }
                }
            cl=0;
            }
        else if(input==2)
            {
                cout<<"......Before Please Check Book Details And Note Index Of It......"<<endl;
                cout<<"Enter Book Name And Quantity You Want To Take :"<<endl;
                cout<<"Enter Book Name :: "<<endl;
                cin>>book_name;
                fstream fin;
                string s;
                fin.open("Books.pdf",ios::in);
                while(fin.eof()!=1)
                {
                    fin>>s;
                    if(book_name==s)
                    {
                        index=index+1;
                        break;
                    }
                    else
                    {
                        index=index+1;
                    }
                }
                fin.close();
                string ss;
                fin.open("Books.pdf",ios::in);
                while (fin.eof()!=1)
                {
                    fin>>ss;
                    if(book_name==ss)                  
                    {
                        cout<<"Book Is Available !"<<endl;
                        count++;
                        cout<<"Enter Book Quantity :: "<<endl;
                        cin>>book_qun;
                        string line;
                        int cl=0;
                        ifstream f,f12;
                        f.open("Books.pdf",ios::in);
                        f12.open("Quantity.pdf",ios::in);
                        while(!f12.eof())
                        {
                        cl++;
                        f12>>line;
                        if(cl==index) break;
                        }
                        int data=stoi(line);
                        if(data<book_qun)
                        {
                            cout<<"Sorry Book Quntity is only "<<data<<endl;
                        }
                        else
                        {
                            cout<<"Book is Available You can check out !"<<endl;
                           
                            ofstream f2;
                            f2.open("Avails.pdf",ios::app);
                            cout<<"Enter Your Name -- (First Name Only)";
                            cin>>name;
                            cout<<"Enter Your Id-No -- ";
                            cin>>nameid;
                            f2<<name<<setw(20-(name.length()))<<"|"<<nameid<<setw(20-(nameid.length()))<<"|"<<book_name<<setw(16-(book_name.length()))<<"|"<<to_string(book_qun)<<setw(15-(to_string(book_qun).length()))<<"|"<<index<<endl;
                            //NOW MAIN TASK IS UPDATE QUANTITY LIST HOW TO UPDATE ??? IT WE NOW POSITION TO BE UPDATE BUT HOW?? IS MAIN QUESTION .
                            // cout<<"Your Code Is "<<code<<endl;
                            // cout<<"Remember Code Its Is Important While Return The Book !!"<<endl;
                            f2.close();
                            cout<<"Thank you for using our service"<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<index;
                            fstream read_file;
                            // Open the file with the provided filename
                            read_file.open("Quantity.pdf");
                            vector<string> lineupdates;
                            string lineupdate;
                            while (getline(read_file, lineupdate))
                                lineupdates.push_back(lineupdate);
                            read_file.close();
                            ofstream write;
                            write.open("Quantity.pdf");
                            index--;
                            for(int i=0;i<lineupdates.size();i++)
                            {
                                if(i!=index)
                                {
                                    write<<lineupdates[i]<<endl;
                                }
                                else
                                {
                                    write<<data-book_qun<<endl;
                                }
                            }
                            write.close();
                        }
                    
                    f.close();
                    f12.close();
                    break;
                    }
                }
                if(count==0)
                {
                    cout<<"Book Is Not Available Now";
                }
                fin.close();
                count=0;
                index=0;
            }
        else if(input==3)
            {
            cout<<"Enter Book Name That You take ";
            cin>>book_name;
            cout<<"Enter Quntity"<<endl;
            cin>>book_qun;
            cout<<"Enter Name As Enter in Details Form - "<<endl;
            cin>>name;
            //Adding Book Again In Quantity List # Finnaly Reach Towards Goal;
            fstream fin;
            string sss;
            fin.open("Books.pdf",ios::in);
                while(fin.eof()!=1)
                {
                    fin>>sss;
                    if(book_name==sss)
                    {
                        index=index+1;
                        break;
                    }
                    else
                    {
                        index=index+1;
                    }
                }
            fin.close();
            ifstream f12;
            f12.open("Quantity.pdf",ios::in);
            int cl=0;
            string line;
            while(!f12.eof())
            {
            cl++;
            f12>>line;
            if(cl==index) break;
            }
            int data=stoi(line);
            index--;

            fstream read_file;
            read_file.open("Quantity.pdf");
            vector<string> qunupdates;
            string qunupdate;
            while (getline(read_file, qunupdate))
                qunupdates.push_back(qunupdate);
            read_file.close();
            
            ofstream write;
            write.open("Quantity.pdf");
            for(int i=0;i<qunupdates.size();i++)
            {
                if(i!=index)
                {
                    write<<qunupdates[i]<<endl;
                }
                else
                {
                    write<<data+book_qun<<endl;
                }
            }
            write.close();
            
            // vector<string> nameupdates;
            // string nameupdate;
            // Now Update Avails List So We Remove Data From That ;
            
            cout<<"Submitted Sucessfully"<<endl;
            cout<<"Date--"<<__DATE__<<endl;
            cout<<"TIME--"<<__TIME__<<endl;
            cout<<"Thank You ,Visit Again !!"<<endl;
            cout<<"NAME -- "<<name<<endl;
            cout<<"ID   -- "<<nameid<<"  "<<endl;
            cout<<"BOOK NAME    -- "<<book_name<<endl;
            cout<<"BOOK QUNTITY -- "<<book_qun<<endl;
            cout<<"Thank You For Using Our Service"<<endl;
        }
            
        else if(input==4)
        {
            cout<<" Enter Book Details Book Name And Quantity "<<endl;
            cout<<"  How Many Book Do You Want To Add - ";
            cin>>book;
            ofstream fout;
            ofstream fout2;
            fout.open("Books.pdf",ios_base::app);
            fout2.open("Quantity.pdf",ios_base::app);
            for(int i=0;i<book;i++)
            {
                cout<<"Enter Book Name -- 'Space With Underscore Only' -- ";
                cin.ignore();
                cin>>book_name;
                cout<<"Enter Book Quantity -- ";
                cin>>book_qun;
                fout<<book_name<<endl;
                fout2<<book_qun<<endl;                 
            }
        }
    }
};  



int main()
{     
    library l;
    while(true)
    {
    l.function();
    }
   
   return 0;
}
