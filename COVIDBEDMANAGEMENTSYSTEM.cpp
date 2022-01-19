#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

using namespace std;

class loginn
{
	private:
		char username[50];
		char password[50];
		
	public:
		void log_in();
		void signup();
		void passrecover();
		int checkuser(string, string);
		int mainmenu();
};

class hospital
{
	private:
	int hospital_bed_no;
	char name[30];
	char age[5];
    char gen[8];
	char address[50];
	char phone[10];
	char bloodgrp[5];
	char past_disease[50];
	
	public:
	void Bedadd(string );
	int check(string, int );
	void display(string);
	int bedsavail(string, int);
	void search(string);
	void modify(string);
	void rec_delete(string);
};

int loginn::checkuser(string filename, string usern)
{
	int flag=0;
	ifstream i1(filename,ios::in);
	while(i1.read((char*)this,sizeof(loginn)))
	{
		if(strcmp(username,usern.c_str())==0)
		{
			flag=1;
			break;
		}
	}
	i1.close();
	return(flag);
}

void loginn::signup()
{
	int flag, flg;
	char cnfpassword[50],ch,c;
	bool iscorrect = 0;
	ofstream file("UserData.txt",ios::app);
	do
	{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t              SIGN-UP\n";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t ENTER THE DETAILS ";
	cout<<"\n\t\t\t\t\t\t _________________________________________________________________ \n";
	
	cout<<"\n\t\t\t\t\t\t\t\t   USERNAME           : ";
	cin>>username;
	flag=checkuser("UserData.txt", username);

	if(flag)
	{
		cout<<"\n\t\t\t\t\t\t SORRY..!!!USERNAME ALREADY EXISTS";
		flg=0;
	}
	else
	{
		int i = 0;
		cout<<"\n\t\t\t\t\t\t\t\t   PASSWORD           : ";
		cin>>password;
		cout<<"\n\t\t\t\t\t\t\t\t   CONFIRM PASSWORD   : ";
		for(i=0; ;)
		{
			ch = getch();
			if((ch>='a'&& ch<='z' || (ch>='A' && ch<='Z') || (ch>='0'&&ch<='9')))
			{
				cnfpassword[i] = ch;
				i++;
				cout<<"*";
			}
			if(ch=='\b'&&i>=1)
			{
				cout<<"\b \b";
				--i;
			}
			if(ch=='\r')
			{
				cnfpassword[i]='\0';
				break;
			}
		}
		if(strcmp(password,cnfpassword)==0)
		{
			file.write((char*)this,sizeof(loginn));
			cout<<"\n\n\t\t\t\t\t\t YOU HAVE REGISTERED SUCCESSFULLY!!!";
		}
		else
		{
			cout<<"\n\n\t\t\t\t\t\t\t\t      PASSWORD DOES NOT MATCH";
			cout<<"\n\n\t\t\t\t\t\t\t\t\t  SIGN-UP FAILED";
			cout<<"\n\n\t\t\t\t\t     DO YOU WANT TO ENTER THE DETAILS AGAIN(PRESS ENTER) OR FOR EXIT TO MAIN MENU(PRESS ESC)";
			c = getch();
			if(c==13)
				flg = 1;
			else if(c==27)
				flg = 0;
			else
				flg = 0;
		}
	}
	}while(flg==1);
	file.close();
}

void loginn::log_in()
{
	int flag, flg=0, i = 0;
	char ch,c;
	char usern[50], pass[50];
	ifstream i1("UserData.txt",ios::in);
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t              LOGIN\n";
		cout<<"\n\t\t\t\t\t\t _________________________________________________________________ \n";	
		cout<<"\n\t\t\t\t\t\t\t\t       USERNAME     : ";
		cin>>usern;
		flag=checkuser("UserData.txt", usern);
		while(i1.read((char*)this,sizeof(loginn)))
		{
		if(flag==0)
		{
			cout<<"\n\t\t\t\t\t\t SORRY..!!!USER DOES NOT EXIST";
			flg=0;
			getch();
		}
		else
		{
		cout<<"\n\t\t\t\t\t\t\t\t       PASSWORD     : ";
		for(i=0; ;)
		{
				ch = getch();
			if((ch>='a'&& ch<='z' || (ch>='A' && ch<='Z') || (ch>='0'&&ch<='9')))
			{
				pass[i] = ch;
				i++;
				cout<<"*";
			}
			if(ch=='\b'&&i>=1)
			{
				cout<<"\b \b";
				--i;
			}
			if(ch=='\r')
			{
				pass[i]='\0';
				break;
			}
		}
			if(strcmp(pass,password)==0)
			{
				cout<<"\n\n\t\t\t\t\t\t\t\t\t  LOGIN SUCCESSFUL";
				cout<<"\n\n\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE!!";
				getch();
				mainmenu();
				flg = 0;
			}
			else
			{
				cout<<"\n\n\t\t\t\t\t\t\t\t    WRONG USERNAME OR PASSWORD";
				cout<<"\n\n\t\t\t\t\t\t\t\t\t   LOGIN FAILED";
				cout<<"\n\n\t\t\t\t\t\t            FOR GOING BACK TO MAIN MENU(PRESS ENTER)";
				c = getch();
				if(c==13)
					flg = 0;  
				else if(c==27)
					flg = 0;
				else
					flg = 0;
			}
			}
		}
	}while(flg==1);
	i1.close();
}

void loginn::passrecover()
{
	char usern[50],cnfpassword[50],ch;
	long pos,flag=0;
	fstream file("UserData.txt",ios::in|ios::out|ios::binary);
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t          PASSWORD RECOVERY\n";
	cout<<"\n\t\t\t\t\t\t _________________________________________________________________ \n";	
	cout<<"\n\t\t\t\t\t\t\t\t   USERNAME           : ";
	cin>>usern;
	
	while(file.read((char*)this,sizeof(loginn)))
	{
		pos=file.tellg();

	if(strcmp(usern,username)==0)
		{
			int i = 0;
		cout<<"\n\t\t\t\t\t\t\t\t   PASSWORD           : ";
		cin>>password;
		cout<<"\n\t\t\t\t\t\t\t\t   CONFIRM PASSWORD   : ";
		for(i=0; ;)
		{
			ch = getch();
			if((ch>='a'&& ch<='z' || (ch>='A' && ch<='Z') || (ch>='0'&&ch<='9')))
			{
				cnfpassword[i] = ch;
				i++;
				cout<<"*";
			}
			if(ch=='\b'&&i>=1)
			{
				cout<<"\b \b";
				--i;
			}
			if(ch=='\r')
			{
				cnfpassword[i]='\0';
				break;
			}
		}
		if(strcmp(password,cnfpassword)==0)
		{
			file.seekg(pos-sizeof(loginn));
			file.write((char*)this,sizeof(loginn));
			cout<<"\n\n\t\t\t\t\t\t PASSWORD HAS BEEN RECOVERED SUCCESSFULLY";
			flag=1;
			break;
		}
		else
		{
			cout<<"\n\n\n\t\t\t\t\t\t\t\t      PASSWORD DOES NOT MATCH";
			cout<<"\n\n\t\t\t\t\t\t\t\t     PASSWORD RECOVERY FAILED!!";
			flag=1;
			break;
		}
		}
	}

	if(flag==0)
		cout<<"\n\t\t\t\t\t\t SORRY USERNAME DOES NOT EXIST!!";

	file.close();
}

bool pr(char phone[])
{
	if (strlen(phone) > 10 || strlen(phone) != 10)
        return false;
    else
        return true;
}

void hospital::Bedadd(string filename)
{	
	system("cls");
	int n,flag;
	ofstream file(filename,ios::app);

	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t         ENTER PATIENT DETAILS\n";
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	cout<<"\n\n\t\t\t\t\t\t\t\t\t HOSPITAL BED NUMBER: ";
	cin>>n;
	flag=check(filename, n);

	if(flag)
		cout<<"\n\t\t\t\t\t\t SORRY..!!!HOSPITAL BED IS ALREADY BOOKED";
	else
	{
		hospital_bed_no=n;
		cout<<"\n\t\t\t\t\t\t\t\t  NAME  : ";
		cin>>name;
		cout<<"\n\t\t\t\t\t\t\t\t  AGE   : ";
		cin>>age;
		cout<<"\n\t\t\t\t\t\t\t\t  GENDER(M/F/O)  : ";
		cin>>gen;
		cout<<"\n\t\t\t\t\t\t\t\t  ADDRESS : ";
		cin>>address;
		do
		{
		cout<<"\n\t\t\t\t\t\t\t\t  PHONE NO.: ";
		cin>>phone;
		if (pr(phone) == false) 
		{
            cout<<"\n\t\t\t\t\t\t\t\t  ERROR";
        }
    	}while (pr(phone) == false);
    	cout<<"\n\t\t\t\t\t\t\t\t  BLOOD GROUP: ";
		cin>>bloodgrp;
		cout<<"\n\t\t\t\t\t\t\t\t  PAST DISEASE (IF ANY ELSE WRITE NA): ";
		cin>>past_disease;
		//*ptr = *ptr - 1;
		file.write((char*)this,sizeof(hospital));
		cout<<"\n\t\t\t\t\t\t YOU HAVE SUCCESSFULLY BOOKED THE HOSPITAL BED!!!";
	}
	cout<<"\n\n\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE!!";
	getch();
	file.close();
}

int hospital::bedsavail(string filename, int data)
{
	int count = 0;
	ifstream file(filename,ios::in);
	while(file.read((char*)this,sizeof(hospital)))
	{
		++count;
	}
	data = data - count;
	file.close();
	return data;
}

int hospital::check(string filename, int r)
{
	int flag=0;
	ifstream i1(filename,ios::in);
	while(i1.read((char*)this,sizeof(hospital)))
	{
		if(hospital_bed_no==r)
		{
			flag=1;
				break;
		}
	}
	i1.close();
	return(flag);
}

void hospital::display(string filename)
{
	system("cls");
	ifstream i1(filename,ios::in);
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       DISPLAY ALL ALLOTED BEDS\n";
	cout<<"\n\n\n\t\t\t\t\t\t\t\t         LIST OF ALLOTED BEDS\n";
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";

	while(i1.read((char*)this,sizeof(hospital)))
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t      BED NO.      :      "<<hospital_bed_no<<"\n";
	    cout<<"\n\t\t\t\t\t\t\t\t      NAME         :      "<<name<<"\n";
	    cout<<"\n\t\t\t\t\t\t\t\t      AGE          :      "<<age<<"\n";
	    cout<<"\n\t\t\t\t\t\t\t\t      GENDER       :      "<<gen<<"\n";
		cout<<"\n\t\t\t\t\t\t\t\t      PHONE NO.    :      "<<phone<<"\n";
		cout<<"\n\t\t\t\t\t\t\t\t      BLOOD GROUP  :      "<<bloodgrp<<"\n";
	    cout<<"\n\t\t\t\t\t\t\t\t      ADDRESS      :      "<<address<<"\n";
	    cout<<"\n\t\t\t\t\t\t\t\t      PAST DISEASE :      "<<past_disease<<"\n";
	    cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	}
	cout<<"\n\n\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE!!";
	getch();
	i1.close();
}

void hospital::search(string filename)
{        
	int Choice;
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t         SEARCH PATIENT DETAILS\n";
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	
	cout<<"\n\t\t\t\t\t\t\t\t         ENTRY MENU\n";
    cout<<"\n\t\t\t\t\t\t\t\t         1. SEARCH BY BED NUMBER\n";
    cout<<"\n\t\t\t\t\t\t\t\t         2. SEARCH BY NAME\n";
    cout<<"\n\t\t\t\t\t\t\t\t         3. GO BACK TO MAIN MENU\n";
    cout<<"\n\t\t\t\t\t\t\t\t         ENTER YOUR CHOICE: ";
    cin>>Choice;
    
    switch(Choice)
    {
    	case 1:
    		{
            ifstream myfile(filename,ios::in);
			int r,flag=0;
            cout<<"\n\t\t\t\t\t\t\t\t ENTER THE HOSPITAL BED NUMBER: ";
			cin>>r;
			while(myfile.read((char*)this,sizeof(hospital)))
			{
				if(hospital_bed_no==r)
				{
					cout<<"\n\n\t\t\t\t\t\t\t\t    BED NO.      :      "<<hospital_bed_no<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    NAME         :      "<<name<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    AGE          :      "<<age<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    GENDER       :      "<<gen<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    PHONE NO.    :      "<<phone<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    BLOOD GROUP  :      "<<bloodgrp<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    ADDRESS      :      "<<address<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    PAST DISEASE :      "<<past_disease<<"\n";
					flag=1;
					break;
				}
			}
			if(flag==0)
			cout<<"\n\n\t\t\t\t\t\t SORRY HOSPITAL BED NO. NOT FOUND OR VACANT !!";
			cout<<"\n\n\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE!!";
			getch();
			myfile.close();
		    break;
			}

        case 2:
        	{
        	char patname[50];
            ifstream myfile(filename,ios::in);
			int flg=0;
            cout<<"\n\t\t\t\t\t\t\t\t ENTER THE NAME OF THE PATIENT: ";
			cin>>patname;
			while(myfile.read((char*)this,sizeof(hospital)))
			{
				while(strcmp(patname,name)==0)
				{
					cout<<"\n\n\t\t\t\t\t\t\t\t    BED NO.      :      "<<hospital_bed_no<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    NAME         :      "<<name<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    AGE          :      "<<age<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    GENDER       :      "<<gen<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    PHONE NO.    :      "<<phone<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    BLOOD GROUP  :      "<<bloodgrp<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    ADDRESS      :      "<<address<<"\n";
			        cout<<"\n\t\t\t\t\t\t\t\t    PAST DISEASE :      "<<past_disease<<"\n";
					flg=1;
					break;
				}
			}
			if(flg==0)
			cout<<"\n\n\t\t\t\t\t\t SORRY PATIENT RECORD DOES NOT EXIST!!";
			cout<<"\n\n\t\t\t\t\t\t PRESS ANT KEY TO CONTINUE!!";
			getch();
			myfile.close();
		    break;
			}
        
        case 3:
        	break;
        	
        default:
            cout<<"\n\t\tINVALID CHOICE";
	}
}

void hospital::modify(string filename)
{
	system("cls");
	int r;
	long pos,flag=0;
	fstream file(filename,ios::in|ios::out|ios::binary);
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       ENTER NEW PATIENT DETAILS\n";
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	cout<<"\n\t\t\t\t\t\t\t\t  ENTER THE HOSPITAL BED NUMBER: ";
	cin>>r;
	while(file.read((char*)this,sizeof(hospital)))
	{
		pos=file.tellg();

	if(hospital_bed_no==r)
		{
			cout<<"\n\t\t\t\t\t\t\t\t NAME: ";
			cin>>name;
			cout<<"\n\t\t\t\t\t\t\t\t AGE: ";
			cin>>age;
			cout<<"\n\t\t\t\t\t\t\t\t GENDER(M/F/O): ";
			cin>>gen;
			cout<<"\n\t\t\t\t\t\t\t\t ADDRESS: ";
			cin>>address;
			do
			{
			cout<<"\n\t\t\t\t\t\t\t\t PHONE NO.: ";
			cin>>phone;
			if (pr(phone) == false) 
			{
	            cout<<"\n\t\t\t\t\t\t\t\t  ERROR";
	        }
	    	}while (pr(phone) == false);
	    	cout<<"\n\t\t\t\t\t\t\t\t BLOOD GROUP: ";
			cin>>bloodgrp;
			cout<<"\n\t\t\t\t\t\t\t\t PAST DISEASE (IF ANY ELSE WRITE NA): ";
			cin>>past_disease;

			file.seekg(pos-sizeof(hospital));
			file.write((char*)this,sizeof(hospital));
			cout<<"\n\t\t\t\t\t\t PATIENT RECORD IS MODIFIED SUCCESSFULLY";
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n\t\t\t\t\t\t SORRY HOSPITAL BED NO. NOT FOUND OR VACANT!!";

	file.close();
}

void hospital::rec_delete(string filename)
{
	system("cls");
	int r;
	int flag=0;
	char ch;
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       DELETE PATIENT DETAILS\n";
	cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
	cout<<"\n\t\t\t\t\t\t\t\t  ENTER THE HOSPITAL BED NUMBER: ";
	cin>>r;
	ifstream i1(filename,ios::in);
	ofstream o1("temp.txt",ios::out);

	while(i1.read((char*)this,sizeof(hospital)))
	{
		if(hospital_bed_no==r)
		{
			cout<<"\n\n\t\t\t\t\t\t\t\t  BED NO.      :      "<<hospital_bed_no<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  NAME         :      "<<name<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  AGE          :      "<<age<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  GENDER       :      "<<gen<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  PHONE NO.    :      "<<phone<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  BLOOD GROUP  :      "<<bloodgrp<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  ADDRESS      :      "<<address<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t\t  PAST DISEASE :      "<<past_disease<<"\n";
			cout<<"\n\n\t\t\t\t\t\t DO YOU WANT TO DELETE THIS RECORD(Y/N): ";
			cin>>ch;
			if ( ch=='Y' || ch == 'y' )
			{
				//*ptr = *ptr + 1;
			cout<<"\n\t\t\t\t\t\t RECORD HAVE BEEN DELETED SUCCESSFULLY!!!";
			}

			if ( ch=='N' || ch == 'n' )
			{
			o1.write((char*)this,sizeof(hospital));
			cout<<"\n\t\t\t\t\t\t RECORD HAVE NOT BEEN DELETED!!!";
			}
			flag=1;
		}
		else
		{
			o1.write((char*)this,sizeof(hospital));
		}
	}
	i1.close();
	o1.close();

	if(flag==0)
		cout<<"\n\t\t\t\t\t\t SORRY HOSPITAL BED NO. NOT FOUND OR VACANT!!";
	else
	{
		remove(filename.c_str());
		rename("temp.txt",filename.c_str());
	}
}

int login()
{
	loginn user;
	char a1;
	int Choice;
	do {
        system("cls");
        system("color 3");
        cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t      WELCOME\n";
        cout<<"\n\t\t\t\t\t\t\t\t\t        TO\n";
        cout<<"\n\t\t\t\t\t\t\t\t     COVID BED MANAGEMENT SYSTEM\n\n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\n\t\t\t\t\t\t\t\t     ENTRY MENU\n";
        cout<<"\n\t\t\t\t\t\t\t\t     1. LOGIN\n";
        cout<<"\n\t\t\t\t\t\t\t\t     2. SIGN-UP\n";
        cout<<"\n\t\t\t\t\t\t\t\t     3. FORGOTTEN PASSWORD?\n";
        cout<<"\n\t\t\t\t\t\t\t\t     4. EXIT\n";
        cout<<"\n\t\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        cin>>Choice;

        switch (Choice) {
        case 1:
            system("cls");
            user.log_in();
            break;

        case 2:
        	system("cls");
        	user.signup();
            break;

        case 3:
            system("cls");
            user.passrecover();
            break;

        case 4:
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t       THANK YOU\n";
            cout<<"\n\t\t\t\t\t\t\t\t        WISH TO SEE YOU NEXT TIME\n";
            getch();
            exit(0);

        default:
            cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
        }
        cout<<"\n\n\t\t\t\t\t\t DO YOU WISH TO RUN PROGRAM AGAIN(Y/N): ";
        cin>>a1;
    } while (a1 == 'Y' | a1 == 'y');
	return 0;
}

int loginn::mainmenu()
{
	int Choice,ch;
    int a, b, c, d, e, f;
    char a1, m;
    hospital vedan,fortis,aiims,Bed;
    int vedbed = 50, aiimsbed = 100, fortisbed = 75;
    string filevedanta = "Vedanta.txt";
    string filefortis = "FORTIS.txt";
    string fileaiims = "AIIMS.txt";
    do {
        system("cls");
        system("color 3");
        cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t      WELCOME\n";
        cout<<"\n\t\t\t\t\t\t\t\t\t        TO\n";
        cout<<"\n\t\t\t\t\t\t\t\t     COVID BED MANAGEMENT SYSTEM\n\n";
        cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
        cout<<"\n\t\t\t\t\t\t\t\t     ENTRY MENU\n";
        cout<<"\n\t\t\t\t\t\t\t\t     1. DISPLAY ALL ALLOTED BEDS\n";
        cout<<"\n\t\t\t\t\t\t\t\t     2. SEARCH ALLOTED BED\n";
        cout<<"\n\t\t\t\t\t\t\t\t     3. BOOK A HOSPITAL BED\n";
        cout<<"\n\t\t\t\t\t\t\t\t     4. MODIFY PATIENT RECORD\n";
        cout<<"\n\t\t\t\t\t\t\t\t     5. DELETE PATIENT RECORD\n";
        cout<<"\n\t\t\t\t\t\t\t\t     6. EXIT\n";

        cout<<"\n\t\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        cin>>Choice;

        switch (Choice) {
        case 1:
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t      DISPLAY ALL ALLOTED BEDS\n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\n\t\t\t\t\t\t\t     HOSPITAL NAME                 BEDS AVAILABLE\n";
            cout<<"\n\n\t\t\t\t\t\t\t     1. VEDANTA HOSPITAL\t\t"<<vedan.bedsavail(filevedanta,vedbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     2. FORTIS HOSPITAL\t\t\t"<<fortis.bedsavail(filefortis,fortisbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     3. AIIMS\t\t\t\t"<<aiims.bedsavail(fileaiims,aiimsbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     4. GO BACK TO THE MAIN MENU\n";
	        cout<<"\n\n\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        	cin>>ch;
        	
        	switch(ch)
        	{
        		case 1:
        			vedan.display(filevedanta);
        			break;
        			
        		case 2:
        			fortis.display(filefortis);
        			break;
        			
        		case 3:
        			aiims.display(fileaiims);
        			break;
        		
        		case 4:
        			break;
        		
        		default:
        			cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
			}
            
            break;

        case 2:
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t     SEARCH FOR AN ALLOTED BED\n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\n\t\t\t\t\t\t\t     HOSPITAL NAME                 BEDS AVAILABLE\n";
            cout<<"\n\n\t\t\t\t\t\t\t     1. VEDANTA HOSPITAL\t\t"<<vedan.bedsavail(filevedanta,vedbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     2. FORTIS HOSPITAL\t\t\t"<<fortis.bedsavail(filefortis,fortisbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     3. AIIMS\t\t\t\t"<<aiims.bedsavail(fileaiims,aiimsbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     4. GO BACK TO THE MAIN MENU\n";
	        cout<<"\n\n\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        	cin>>ch;
        	
        	switch(ch)
        	{
        		case 1:
        			vedan.search(filevedanta);
        			break;
        			
        		case 2:
        			fortis.search(filefortis);
        			break;
        			
        		case 3:
        			aiims.search(fileaiims);
        			break;
        		
        		case 4:
        			break;
        	
        		default:
        			cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
			}
            break;

        case 3:
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t        BOOK HOSPITAL BEDS\n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\n\t\t\t\t\t\t\t     HOSPITAL NAME                 BEDS AVAILABLE\n";
            cout<<"\n\n\t\t\t\t\t\t\t     1. VEDANTA HOSPITAL\t\t"<<vedan.bedsavail(filevedanta,vedbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     2. FORTIS HOSPITAL\t\t\t"<<fortis.bedsavail(filefortis,fortisbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     3. AIIMS\t\t\t\t"<<aiims.bedsavail(fileaiims,aiimsbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     4. GO BACK TO THE MAIN MENU\n";
	        cout<<"\n\n\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        	cin>>ch;
        	
        	switch(ch)
        	{
        		case 1:
        			vedan.Bedadd(filevedanta);
        			break;
        			
        		case 2:
        			fortis.Bedadd(filefortis);
        			break;
        			
        		case 3:
        			aiims.Bedadd(fileaiims);
        			break;
        			
        		case 4:
        			break;
        	
        		default:
        			cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
			}
            break;

        case 4:
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t       MODIFY PATIENT DETAILS\n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\n\t\t\t\t\t\t\t     HOSPITAL NAME                 BEDS AVAILABLE\n";
            cout<<"\n\n\t\t\t\t\t\t\t     1. VEDANTA HOSPITAL\t\t"<<vedan.bedsavail(filevedanta,vedbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     2. FORTIS HOSPITAL\t\t\t"<<fortis.bedsavail(filefortis,fortisbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     3. AIIMS\t\t\t\t"<<aiims.bedsavail(fileaiims,aiimsbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     4. GO BACK TO THE MAIN MENU\n";
	        cout<<"\n\n\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        	cin>>ch;
        	
        	switch(ch)
        	{
        		case 1:
        			vedan.modify(filevedanta);
        			break;
        			
        		case 2:
        			fortis.modify(filefortis);
        			break;
        			
        		case 3:
        			aiims.modify(fileaiims);
        			break;
        			
        		case 4:
        			break;
        	
        		default:
        			cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
			}
            break;

        case 5:
            system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t       DELETE PATIENT RECORD\n";
            cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
            cout<<"\n\t\t\t\t\t\t\t     HOSPITAL NAME                 BEDS AVAILABLE\n";
            cout<<"\n\n\t\t\t\t\t\t\t     1. VEDANTA HOSPITAL\t\t"<<vedan.bedsavail(filevedanta,vedbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     2. FORTIS HOSPITAL\t\t\t"<<fortis.bedsavail(filefortis,fortisbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     3. AIIMS\t\t\t\t"<<aiims.bedsavail(fileaiims,aiimsbed)<<"\n";
	        cout<<"\n\t\t\t\t\t\t\t     4. GO BACK TO THE MAIN MENU\n";
	        cout<<"\n\n\t\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
        	cin>>ch;
        	
        	switch(ch)
        	{
        		case 1:
        			vedan.rec_delete(filevedanta);
        			break;
        			
        		case 2:
        			fortis.rec_delete(filefortis);
        			break;
        			
        		case 3:
        			aiims.rec_delete(fileaiims);
        			break;
        			
        		case 4:
        			break;
        	
        		default:
        			cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
			}
            break;

        case 6:
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t       THANK YOU\n";
            cout<<"\n\t\t\t\t\t\t\t\t        WISH TO SEE YOU NEXT TIME\n\n\n\n\n\n";
            getch();
            exit(0);

        default:
            cout<<"\n\t\t\t\t\t\t INVALID CHOICE";
        }
        cout<<"\n\n\t\t\t\t\t\t DO YOU WISH TO RUN PROGRAM AGAIN(Y/N): ";
        cin>>a1;
    } while (a1 == 'Y' | a1 == 'y');
    return 0;
}

int welcome()
{
	system("color 3");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t _______________________________________________________________________________________\n";
	  cout<<"\t\t\t\t\t|                                           		                                |\n";
	  cout<<"\t\t\t\t\t|                                           		                                |\n";
	  cout<<"\t\t\t\t\t|                                           		                                |\n";
	  cout<<"\t\t\t\t\t|                                           		                                |\n";
	  cout<<"\t\t\t\t\t|                                           		                                |\n";
	  cout<<"\t\t\t\t\t|                                           		                                |\n";
	  cout<<"\t\t\t\t\t|                                       WELCOME TO                                      |\n";
	  cout<<"\t\t\t\t\t|                                                                                       |\n";
	  cout<<"\t\t\t\t\t|                           	COVID BED MANAGEMENT SYSTEM                             |\n";
	  cout<<"\t\t\t\t\t|                                                                                       |\n";
	  cout<<"\t\t\t\t\t|                                                                                       |\n";
	  cout<<"\t\t\t\t\t|                                                                                       |\n";
	  cout<<"\t\t\t\t\t|                                                                                       |\n";
	  cout<<"\t\t\t\t\t|                                                                                       |\n";
	  cout<<"\t\t\t\t\t|                            PROJECT BY -> KUNAL JALUTHRIA                              |\n";
	  cout<<"\t\t\t\t\t|_______________________________________________________________________________________|\n";
	  
	  system("pause");
	  return 0;
}

int main()
{
	welcome();
	login();
	return 0;
}
