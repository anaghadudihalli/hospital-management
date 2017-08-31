#include<fstream.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>


void font();
void menu();
void receptionist();
void bill();
void admin();
void blood();
void doctor();
void healthcamps();
void fixapp();
void date();
void polygon();




/*---------------------------------------------------------------------
		     GRAPHICS STARTS
  ---------------------------------------------------------------------*/

void polygon()
{  /* our polygon array */
   int poly[10],poly2[10];

   poly[0] =10;
   poly[1] =10;

   poly[2] = 630;
   poly[3] = 10;

   poly[4] = 630;
   poly[5] = 465;

   poly[6] = 10;
   poly[7] = 465;

   poly[8]=10;
   poly[9]=10;

   //________________________________________________

   poly2[0] = 0;
   poly2[1] = 0;

   poly2[2] = 639;
   poly2[3] = 0;

   poly2[4] = 639;
   poly2[5] = 479;


   poly2[6] = 0;
   poly2[7] = 479;

   poly2[8]=0;
   poly2[9]=0;


   drawpoly(5, poly2);
   setfillstyle(SOLID_FILL,CYAN);

   fillpoly(5, poly2);

   drawpoly(5, poly);
   setfillstyle(SOLID_FILL,BLACK);
   fillpoly(5, poly);

}



void font()
 {
    clrscr();
    cleardevice();   // CLEARS GRAPHICS SCREEN

    setbkcolor(BROWN);

    setcolor(BLUE);
    polygon();
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(160,60,"CUTIS HOSPITAL");

 }



 void date()
 {
    struct date d;
    getdate(&d);
    cout<<"\n\t\t";
    printf(" %d", d.da_day);
    printf("/ %d", d.da_mon);
    printf("/ %d", d.da_year);

 }



void time()
{
   struct  time t;
   gettime(&t);
   cout<<"\t\t\t";
   printf(" %2d:%02d:%02d\n",t.ti_hour, t.ti_min, t.ti_sec);

}




/*---------------------------------------------------------------------
		       GRAPHICS ENDS
  ---------------------------------------------------------------------*/





/*---------------------------------------------------------------------
		      ADMINISTRATION STARTS
 ----------------------------------------------------------------------*/

class doctor

{
    private:
	    int doc_id;                 //DOCTOR'S ID

	    char name[30];              //DOCTOR'S NAME

	    long salary;                //DOCTOR'S SALARY

	    char specialisation[20];    //DOCTOR'S SPECIALISATION

	    int exp;                    //DOCTOR'S EXPERIENCE
     public:

	    long fee;                   //DOCTOR'S CONSULTATION FEE

	    void input();               //INPUT DOCTOR'S DETAILS

	    void output();              //DISPLAY DOCTOR'S DETAILS

	    void calsal();              //CALACULATING SALARY OF DOCTOR DEPENDING ON HIS/HER EXPERIENCE

	    void doc_add();             //APPOINTING A DOCTOR

	    void doc_remove();          //FIRING A DOCTOR

	    void edit();                //EDITING DOCTOR DETAILS

	    long getfee()               //RETURNS FEE

	      {



		 return fee;


	      }



	    int getid()                 //RETURNS DOCTOR'S ID
	      {


		 return doc_id;


	      }

	   char *getname()              //RETURNS DOCTOR'S NAME
	      {

		return name;

	      }

}doc;




void doctor::input()
    {

	cout<<"\n\n\n\n\n\n\n\n\n\t\t   ENTER THE DETAILS OF THE DOCTOR\n";

	cout<<"\n\t\t\tDOCTOR ID        : ";
	cin>>doc_id;

	cout<<"\n\t\t\tNAME             : ";
	gets(name);

	cout<<"\n\t\t\tSPECIALISATION   : ";
	gets(specialisation);

	cout<<"\n\t\t\tEXPERIENCE       : ";
	cin>>exp;

	cout<<"\n\t\t\tCONSULTATION FEE : ";
	cin>>fee;

	calsal();

   }




void doctor::output()
   {


	cout<<"\n\n\n\t\t\tDetails of the doctor are : \n";

	cout<<"\n\t\t\tDOCTOR ID        : ";
	cout<<doc_id;

	cout<<"\n\t\t\tNAME             : ";
	cout<<name;

	cout<<"\n\t\t\tSPECIALISATION   : ";
	cout<<specialisation;

	cout<<"\n\t\t\tEXPERIENCE       : ";
	cout<<exp;

	cout<<"\n\t\t\tSALARY           : ";
	cout<<salary;

	cout<<"\n\t\t\tCONSULTATION FEE : ";
	cout<<fee;


   }



void doctor::calsal()
   {

      if(exp>30)
	 salary=300000;

	    else if(exp>20)
	       salary=200000;

		  else if(exp>10)
		      salary=100000;

			  else
			    salary=50000;


    }





void doctor::doc_add()
{
    cleardevice();
    clrscr();
    font();

    ofstream fout2;
    fout2.open("doctor.txt",ios::binary|ios::app);
    doc.input();
    fout2.write((char*)&doc,sizeof(doc));            //WRITING INTO DOCTOR.TXT

    fout2.close();

}





void doctor::doc_remove()
{

    cleardevice();
    clrscr();
    font();

    int id_;
    cout<<"\n\n\n\n\n\n\n\n\n\tENTER THE ID OF THE DOCTOR TO BE DISMISSED :\t";
    cin>>id_;
    cout<<endl;

    ifstream fin2;
    fin2.open("doctor.txt",ios::binary);

    ofstream fout3;
    fout3.open("temp.dat",ios::binary);

    while(!fin2.eof())
      {

	   fin2.read((char*)&doc,sizeof(doc));

	   if(fin2.eof())
		break;

	   if(doc.getid()!=id_)
		fout3.write((char*)&doc,sizeof(doc));

      }

    fin2.close();

    fout3.close();

    cout<<"\n\n\n\t\t\tDOCTOR DISSMISSED...!!!\n";

    remove("doctor.txt");
    rename("Temp.dat","doctor.txt");

}




void doctor::edit()
{

    int id2,e;

    cout<<"\n\n\n\n\n\n\n\n\n\t\tENTER THE ID NUMBER OF THE DOCTOR  : ";
    cin>>id2;
    cout<<endl;

    ofstream fout5("temp.txt",ios::binary|ios::app);

    ifstream fin4("doctor.txt",ios::binary|ios::in);

    while(!fin4.eof())
     {

	 fin4.read((char*)&doc, sizeof(doc));

	 if(fin4.eof())
		break;


	 if(id2==doc.getid())
	    {
		cout<<"\n\t\tENTER THE EXPERIENCE OF THE DOCTOR : ";
		cin>>e;
		cout<<endl;
		doc.exp=e;
		doc.calsal();
		doc.output();

	    }


	 fout5.write((char*)&doc,sizeof(doc));      // WRITING TO TEMP.TXT


    }

    fin4.close();
    fout5.close();

    remove("doctor.txt");
    rename("temp.txt","doctor.txt");

}



void admin()
{

    int choice3,choice4;
    char ch2,dochoice;


    do
    {

       label4:
       cleardevice();
       clrscr();
       font();

       cout<<"\n\n\n\n\n\n\n\n\n\t\t      1. APPOINT / DISSMISS A DOCTOR\n";
       cout<<"\n\t\t      2. VIEW DETAILS OF A DOCTOR\n";
       cout<<"\n\t\t      3. EDITING THE DOCTOR DETAILS\n";
       cout<<"\n\t\t      4. BACK TO HOME\n";
       cout<<"\n\t\t      5. EXIT\n";


       cout<<"\n\n\t\t\tENTER YOUR CHOICE\t";
       cin>>choice3;


       switch(choice3)
	{

	  case 1:
		  label5:
		  cleardevice();
		  clrscr();
		  font();

		  cout<<"\n\n\n\n\n\n\n\n\n\t\t\t    (1)TO APPOINT A DOCTOR \n\n";
		  cout<<"\t\t\t    (2)TO DISSMISS A DOCTOR \n\n";
		  cout<<"\t\t\t    (3)BACK \n\n";

		  cout<<"\n\t\t  ENTER YOUR CHOICE\n\t\t\t";
		  cin>>choice4;

		  switch(choice4)
		   {

			case 1:
				cleardevice();
				clrscr();
				font();

				doc.doc_add();

				break;


			case 2:
				cleardevice();
				clrscr();
				font();

				doc.doc_remove();

				break;


			case 3:
				goto label4;


		       default:
				cout<<"\n\n\n\n\t\t\t\tWRONG CHOICE..!!\n\n\t\t\t\t ENTER AGAIN\n";
				getch();

				goto label5;

		   }

		   break;

	  case 2 :
		   label6:
		   int id,flag=0;

		   cleardevice();
		   clrscr();
		   font();

		   cout<<"\n\n\n\n\n\n\n\n\n\t\t\tENTER DOCTOR ID : ";
		   cin>>id;

		   ifstream fin3("doctor.txt",ios::binary|ios::out);
		   while(!fin3.eof())
		    {
			fin3.read((char*)&doc,sizeof(doc));

			if(fin3.eof())
			     break;

			if(doc.getid()==id)
			   {
			       doc.output();
			       flag=1;
			   }

		    }

		   fin3.close();

		   if(flag==0)
		       cout<<"\n\n\n\t\t\t\tID NOT FOUND...!!!\n";

		   cout<<"\n\n\n\t\t\tDO YOU WANT TO ENTER AGAIN ?? ( Y / N)\n\n\t\t\t\t";
		   cin>>ch2;


		   if(ch2=='y'||ch2=='Y')
		      goto label6;

			 else
			   goto label4;


	  case 3:
		   cleardevice();
		   clrscr();
		   font();

		   doc.edit();

		   break;


	  case 4:
		   cleardevice();
		   clrscr();

		   settextstyle(1,0,1);
		   outtextxy(49,369,"SIGNING OUT....");
		   for(int j=0;j<220;j++)
		    {
			rectangle(400+j,400,20+j,401);
			delay(20);

		    }

		   menu();

		   break;

	  case 5:
		   exit(0);

		   break;

	 default:
		   cout<<"\n\t\t\t\tINVALID CHOICE..!!\n";
		   cout<<"\a";
		   cout<<"\n\t\t\t\t  ENTER AGAIN";
		   getch();

		   goto label4;

	}


    cout<<"\n\n\n\t\t\tDO YOU WANT TO CONTINUE IN ADMINISTRATION?? ( Y / N)\n\t\t\t";
    cin>>dochoice;


    }

    while(dochoice=='Y'||dochoice=='y');

    if(dochoice!='Y'||dochoice!='y')
    {

       menu();

    }



}




/*----------------------------------------------------------------------
		     FUNCION RECEPTIONIST STARTS
-----------------------------------------------------------------------*/



class patient
{

  private:
	   int pat_id;                     //PATIENT'S ID

	   char pname[20];                 //PATIENT'S NAME

	   int age;                        //PATIENT'S AGE

	   char gen;                       //PATIENT'S GENDER

	   int ward;                    //PATIENT'S WARD No.

	   char problem[30];               //PATIENT'S PROBLEM

	   char cndoc[30];                 //NAME OF THE CONSULTING DOCTOR

	   char room[25];                  //PATIENT'S ROOM TYPE

  public:
	   void inputdetails();            //INPUT PATIENT'S DETAILS

	   void dispdetails();             //DISPLAY PATIENT'S DETAILS

	   void billinfo();                //DISPLAY PATIENT'S DETAILS IN THE BILL

	   void admit();                   //FUNTION FOR ADMITTING THE PATIENT

	   void discharge();               //FUNTION FOR DISCHARGING THE PATIENT

	   void edit();                    //FUNTION FOR EDITING THE PATIENT

	   long prc(int);                  //FUNCTION FOR CALCULATING PATIENT'S ROOM CHARGES

	   void getinfo();

	   char *getcndoc()                //RETURNS NAME OF THE CONSULTING DOCTOR
	     {
		 return cndoc;

	     }

	   int getpat_id()                  //RETURNS PATIENT'S ID
	     {
		 return pat_id;

	     }
	  char *getname()                   //RETURNS PATIENT'S NAME
	     {
		 return pname;

	     }

}pat;



void patient::inputdetails()
{
    cleardevice();
    clrscr();
    font();

    int docch;
    cout<<"\n\n\n\n\n\n\n\n\t\t\tENTER THE DETAILS OF THE PATIENT\n\n";

    cout<<"\t\t\tPATIENT ID              : ";
    cin>>pat_id;

    cout<<"\n\t\t\tPATIENT NAME            : ";
    gets(pname);

    cout<<"\n\t\t\tGENDER                  : ";
    cin>>gen;

    cout<<"\n\t\t\tAGE                     : ";
    cin>>age;

    cout<<"\n\t\t\tPATIENT'S PROBLEM       : ";
    gets(problem);

    cout<<"\n\t\t\tROOM TYPE(ICU/GENERAL)  : ";
    gets(room);

    cout<<"\n\t\t\tWARD                    : ";
    cin>>ward;

     cleardevice();
    clrscr();
    font();
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tCONSULTING DOCTOR \n\n";
    cout<<" \t\t\t1.Dr.Bhumika Shree   - Cardiologist\n";
    cout<<" \t\t\t2.Dr.Anagha Dudihalli- ENT specialist\n";
    cout<<" \t\t\t3.Dr.Mokshitha       - Eye Specialist\n";
    cout<<" \t\t\t4.Dr.Anusha Setty    - Abdomen & Liver Specialist\n";
    cout<<" \t\t\t5.Dr.Gowthami Reddy  - Gyacanologist\n";
    cout<<"\t\t\t\t";
    cin>>docch;

    switch(docch)

      {

	case 1:
		strcpy(cndoc,"Dr.Bhumika Shree");
		break;

	case 2:
		strcpy(cndoc,"Dr.Anagha Dudihalli");
		break;

	case 3:
		strcpy(cndoc,"Dr.Mokshitha");
		break;

	case 4:
		strcpy(cndoc,"Dr.Anusha Setty");
		break;

	case 5:
		strcpy(cndoc,"Dr.Gowthami Reddy");
		break;

	default:
		 cout<<"Invalid choice\n";
		 getch();


}
}


void patient::dispdetails()
{

    cleardevice();
    clrscr();
    font();

    cout<<"\n\n\n\n\n\n\n\n\n\t\t\tPATIENT ID          : ";
    cout<<pat_id;

    cout<<"\n\t\t\tPATIENT NAME        : ";
    cout<<pname;

    cout<<"\n\t\t\tGENDER              : ";
    cout<<gen;

    cout<<"\n\t\t\tAGE                 : ";
    cout<<age;

    cout<<"\n\t\t\tPROBLEM             : ";
    cout<<problem;

    cout<<"\n\t\t\tROOM TYPE           : ";
    puts(room);

    cout<<"\t\t\tWARD No.            : ";
    cout<<ward;

    cout<<"\n\t\t\tCONSULTING DOCTOR   : ";
    cout<<cndoc;


}



void patient::billinfo()
{

    setbkcolor(BLACK);

    cout<<"\n\n\t\t   NAME                  : ";
    cout<<pname;

    cout<<"\n\t\t   GENDER                : ";
    cout<<gen;

    cout<<"\n\t\t   AGE                   : ";
    cout<<age;

    cout<<"\n\t\t   CONSULTING DOCTOR     : ";
    cout<<cndoc;

}



void patient::admit()
{
    clrscr();

    ofstream foutp;
    foutp.open("patient",ios::binary|ios::app);
    pat.inputdetails();
    foutp.write((char*)&pat,sizeof(pat));         //WRITING PATIENT'S DETIALS INTO THE FILE
    foutp.close();

}



long patient::prc(int nod)
{
    long rc;
    if(strcmpi(room,"ICU")==0)
       rc=1500*nod;
	  else
	    rc=800*nod;

      return rc;

}



void patient::discharge()
{   cleardevice();
    clrscr();
    font();

    int p2id;

    cout<<"\n\n\n\n\n\n\n\n\n\t   ENTER THE ID OF THE PATIENT TO BE DISCHARGED :\t";
    cin>>p2id;

    ifstream finp1;
    finp1.open("patient",ios::binary);

    ofstream foutp1;
    foutp1.open("tempat.dat",ios::binary);

    while(!finp1.eof())
      {
	  finp1.read((char*)&pat,sizeof(pat));

	  if(finp1.eof())
	       break;

	  if(pat_id!=p2id)
	     foutp1.write((char*)&pat,sizeof(pat));

      }

    finp1.close();
    foutp1.close();

    remove("patient");
    rename("tempat.dat","patient");

}



void patient::edit()
{
    int id2,e,pateditch,id,wdno;
    char docch[20];

    label11:
    cleardevice();
    clrscr();
    font();

    cout<<"\n\n\n\n\n\n\n\n\n\tENTER THE PATIENT ID WHOSE DETAILS HAS TO BE EDITTED :\t";
    cin>>id;

    ifstream fined("patient",ios::binary|ios::out);
    ofstream fouted("patient",ios::binary|ios::in);

    while(!fined.eof())
     {

	 fined.read((char*)&pat,sizeof(pat));

	 if(fined.eof())
	      break;


	 if(pat.getpat_id()==id)
	  {
	      int docch2;
	      label7:
	      cleardevice();
	      clrscr();
	      font();

	      cout<<"\n\n\n\n\n\n\n\n\n\t\t\tWHAT DO YOU WANT TO EDIT?\n\n";
	      cout<<"\t\t\t1) Patient ward no.\n";
	      cout<<"\t\t\t2) Name of the consulting doctor\n";
	      cout<<"\t\t\t3) BACK\n\n";

	      cout<<"\t\t\t  ";
	      cin>>pateditch;

	      switch(pateditch)
	       {
		    case 1:
			     cleardevice();
			     clrscr();
			     font();

			     cout<<"\n\n\n\n\n\n\n\n\n\t\tENTER THE CHANGED WARD No.:\t";
			     cin>>wdno;

			     pat.ward=wdno;
			     fouted.write((char*)&pat,sizeof(pat));
			     pat.dispdetails();
			     getch();

			     break;

		    case 2:
			     cleardevice();
			     clrscr();
			     font();



    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tCONSULTING DOCTOR \n\n";
    cout<<" \t\t\t1.Dr.Bhumika Shree   - Cardiologist\n";
    cout<<" \t\t\t2.Dr.Anagha Dudihalli- ENT specialist\n";
    cout<<" \t\t\t3.Dr.Mokshitha       - Eye Specialist\n";
    cout<<" \t\t\t4.Dr.Anusha Setty    - Abdomen & Liver Specialist\n";
    cout<<" \t\t\t5.Dr.Gowthami Reddy  - Gyacanologist\n";
    cout<<"\t\t\t\t";
    cin>>docch2;

    switch(docch2)

      {

	case 1:
		strcpy(cndoc,"Dr.Bhumika Shree");
		break;

	case 2:
		strcpy(cndoc,"Dr.Anagha Dudihalli");
		break;

	case 3:
		strcpy(cndoc,"Dr.Mokshitha");
		break;

	case 4:
		strcpy(cndoc,"Dr.Anusha Setty");
		break;

	case 5:
		strcpy(cndoc,"Dr.Gowthami Reddy");
		break;

	default:
		 cout<<"Invalid choice\n";
		 getch();


}


			     strcpy(pat.cndoc,docch);
			     fouted.write((char*)&pat,sizeof(pat));
			     pat.dispdetails();
			     getch();

			     break;

		    case 3:
			     receptionist();

			     break;

		   default:
			     cout<<"\n\n\t\t\t\tINVALID CHOICE...!!\n";
			     cout<<"\a";
			     getch();

			     goto label7;

		}

	  }


	 else


	  {
	      char cho;
	      cout<<"\n\n\n\t\t\t\tNOT FOUND..!!\n";
	      getch();

	      cout<<"\n\t\t\tWANT TO ENTER AGAIN..?? (Y / N) \t";
	      cin>>cho;

	      if(cho=='Y'||cho=='y')
		goto label11;

	       else
		 receptionist();
	  }

     }

  fined.close();

}

/*------------------------------------------------------------------------

			    FIXING APPOINTMENTS STARTS

-------------------------------------------------------------------------*/



void fixapp()

   {

       int amt=1000,fee=1500,chapp,phno;
       char fixappch,name1[20];

       cleardevice();
       clrscr();
       font();

       fixapp:

       cout<<"\n\n\n\n\n\n\n\n\n\t\t\tNAME        : ";
       gets(name1);
       cout<<"\n\t\t\tPHONE No.   : ";
       cin>>phno;
	do                  //DO WHILE LOOP STARTS

	 {


	    cleardevice();
	    clrscr();
	    font();


		 cout<<"\n\n\n\n\n\n\n\n\t\t\t     DOCTORS AVAILABLE\n \n" ;


		 cout<<"\t\t\t1.DENTIST\n\n";
		 cout<<"\t\t\t2.ENT SPECIALIST\n\n";
		 cout<<"\t\t\t3.PHYSICIAN\n\n";
		 cout<<"\t\t\t4.GYNOCOLOGIST\n\n";
		 cout<<"\t\t\t5.SKIN SPECIALIST\n\n";
		 cout<<"\t\t\t6.ORTHOPEDIC SURGEON\n\n";
		 cout<<"\n\t\t\tENTER YOUR CHOICE \t";


		 cin>>chapp;



   cleardevice();
   clrscr();
   font();



   switch(chapp)
       {


	     case 1:

			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tAPPOINTEMENT FIXED!!\n\n";
			cout<<"\t\t\tDOCTOR AVAILABLE FROM 2PM TO 3PM\n\n" ;
			cout<<"\t\t\tCONSULTATION FEE: ";
			cout<<amt;

			break;


       case 2:

			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tAPPOINTMENT FIXED!!\n\n";
			cout<<"\t\t\tDOCTOR AVAILABLE FROM 3PM TO 4.30OM\n\n";
			cout<<"\t\t\tCONSULTATION FEE: ";
			cout<<fee;

			break;


       case 3:

			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tAPPOINTMENT FIXED!!\n\n";
			cout<<"\t\t\tDOCTOR AVAILABLE FROM 4PM TO 5PM\n\n";
			cout<<"\t\t\tCONSULTATION FEE: ";
			cout<<amt;

			break;


       case 4:

			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tAPPOINTMENT FIXED!!\n\n";
			cout<<"\t\t\tDOCTOR AVAILABLE FROM 5PM TO 7PM\n\n";
			cout<<"\t\t\tCONSULTATION FEE: ";
			cout<<fee;

			break;

       case 5:


			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tAPPOINTMENT FIXED!!\n\n";
			cout<<"\t\t\tDOCTOR IS AVAILABLE FROM 5PM TO 6PM\n\n";
			cout<<"\t\t\tCONSULTATION FEE: ";
			cout<<amt;

			break;


       case 6:

			cout<<"\n\n\n\n\n\n\n\n\n\t\t\tAPPOINTMENT FIXED WITH ORTHOPEDIC\n\n";
			cout<<"\t\t\tDOCTOR IS AVAILABLE FROM 6PM TO 7PM\n\n";
			cout<<"\t\t\tCONSULTATION FEE: ";
			cout<<fee;

			break;

       case 7:
			cleardevice();
			clrscr();
			font();
			cout<<"\n\n\n\n\n\n\n\n\nEXITING...";
			getch();
			exit(0);

      default :
			 cout<<"\n\n\n\n\n\n\n\n\t\t\tINVALID CHOICE !!\n\n";
			 cout<<"\a";
			 cout<<"\t\t\tWANT TO DO AGAIN...???\n\n";
			 goto fixapp;

      }

      cout<<"\n\n\t\t\tDO YOU WANT TO FIX MORE APPOINTMENTS?(Y/N) :";
      cin>>fixappch;

}while(fixappch=='Y'||fixappch=='y');
}
/*--------------------------------------------------------------------

		       FIXING APPOINTMENTS ENDS

---------------------------------------------------------------------*/

/*--------------------------------------------------------------------

			BILLING STARTS

----------------------------------------------------------------------*/



void bill()
{

    cleardevice();
    clrscr();
    font();

    patient p;
    int ptempid,nod;

    cout<<"\n\n\n\n\n\n\n\n\n\t\t\tENTER PATIENT'S ID       : ";
    cin>>ptempid;

    cout<<"\n\n\t\t\tENTER THE No. OF DAYS    : ";
    cin>>nod;

    cleardevice();
    clrscr();
    setcolor(RED);

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(160,60,"CUTIS HOSPITAL");


    ifstream finbillp, finbilld;
    finbilld.open("doctor.txt",ios::binary);
    finbillp.open("patient",ios::binary);

    cleardevice();
    setbkcolor(BLACK);
    cout<<"\n\n\n\n\n\n\n\n\t          No.118/15,18th MAIN ROAD,M.R.C.R.EXTENSION\n\t          Vijayanagar,Bangalore-40. Ph no.:080-23406781";
    date();
    time();
    while(!finbillp.eof())
     {
	 finbillp.read((char*)&pat,sizeof(pat));

	 if(!finbillp)
	       break;

	 if(pat.getpat_id()==ptempid)
	   {
	       pat.billinfo();
	       p=pat;
	       break;

	   }

     }


   while(!finbilld.eof())
    {
	 finbilld.read((char*)&doc,sizeof(doc));

	 if(!finbilld)
	       break;

	 if(strcmpi(p.getcndoc(),doc.getname())==0)
	       cout<<"\n\n\t\t\tDOCTOR'S CONSULTATION FEE  : "<<doc.getfee()<<"\n\t\t\t";

    }


   long roomcharge=p.prc(nod);
   cout<<"\n\t\t\tTOTAL ROOM CHARGE          : "<<roomcharge<<"\n";

   cout<<"\n\t\t\tMISCELLENEOUS CHARGES      : "<<900*nod;
   cout<<"\n\t\t\tMEDICINE CHARGES           : "<<200*nod;
float intt=(900*nod)+roomcharge+doc.getfee();
  cout<<"\n\t\t\tVAT(%)                     : "<<(0.12*intt);
   cout<<"\n\t\t\t\t                     ------------\n";
   
   cout<<"\t\t\t                 TOTAL       "<<(900*nod)+roomcharge+doc.getfee() + (0.12*intt);
   


   outtextxy(160,60,"CUTIS HOSPITAL");
   setcolor(WHITE);
   rectangle(80,40,550,450);
   getch();

   finbillp.close();
   finbilld.close();



}
/*--------------------------------------------------------------------

			BILLING ENDS

----------------------------------------------------------------------*/



void receptionist()
{


    int reschoice,pati_id,p_id;
    char exchoice;

    label8:
    cleardevice();
    clrscr();
    font();

    cout<<"\n\n\n\n\n\n\n\n\t\t\t1.ADMITTING THE PATIENT\n\n";
    cout<<"\t\t\t2.DISCHARGING THE PATIENT\n\n";
    cout<<"\t\t\t3.DETAILS OF THE PATIENT\n\n";
    cout<<"\t\t\t4.EDIT THE PATIENT DETAILS\n\n";
    cout<<"\t\t\t5.FIXING APPOINTMENTS\n\n";
    cout<<"\t\t\t6.BILLING\n\n";
    cout<<"\t\t\t7.BACK TO THE MAIN MENU\n\n";
    cout<<"\t\t\t8.EXIT\n\n";

    cout<<"\t\t\tENTER YOUR CHOICE\t";
    cin>>reschoice;
    switch(reschoice)
     {
	  case 1:
		  pat.admit();

		  cout<<"\n\t\t\t    PATIENT ADMITTED..!!\n";
		  getch();

		  goto label8;

	  case 2:
		  pat.discharge();

		  cout<<"\n\n\n\t\t\tPATIENT DISCHARGED..!!\n";
		  getch();

		  goto label8;

	  case 3:
		  cleardevice();
		  clrscr();
		  font();

		  int flag2=0;

		  cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tENTER THE PATIENT'S ID  :\t";
		  cin>>p_id;

		  ifstream finp2("patient",ios::binary|ios::out);
		  while(!finp2.eof())
		   {
		       finp2.read((char*)&pat,sizeof(pat));

		       if(finp2.eof())
			    break;

		       if(pat.getpat_id()==p_id)
			    {
			      flag2=1;
			      pat.dispdetails();

			    }

		   }

		  if(flag2==0)
		    cout<<"\n\n\t\t\t\tNOT FOUND..!!\n";

		  finp2.close();
		  getch();

		  goto label8;

	  case 4:
		  pat.edit();

		  goto label8;

	  case 5:  fixapp();

		  getch();

		  goto label8;

	  case 6:
		  bill();

		  goto label8;

	  case 7:
		  menu();

		  break;

	  case 8:
		  cout<<"\n\t\t\tARE YOU SURE YOU WANT TO EXIT?(Y/N)\t";
		  cin>>exchoice;

		  if(exchoice=='y'||exchoice=='Y')
		   {
		       getch();
		       exit(0);

		   }

		  else
		     goto label8;

	 default:
		  cout<<"\n\t\t\tINVALID CHOICE..!!!\n";
		  cout<<"\a";
		  getch();

		  goto label8;



     }



}






/*--------------------------------------------------------------------

		       BLOOD BANK STARTS

----------------------------------------------------------------------*/


struct address

   {

    int house_no;

    char area[10];

    char city[10];


}add;



class bloodbank
{

  private:

	  char name[20];

	  address add;

	  char bloodg[4];

  public:
	  void inputdata();

	  void outputdata();

	 void adddonor();

	 char *getbb()               //ACCESSOR FUNCTION , RETURN BLOOD GROUP

	 {

	   return bloodg;

	 }

	 char *getname()            //ACCESSOR FUNCTION, RETURNS NAME

	 {

	   return name;


	 }
}bb;




void bloodbank::inputdata()

    {

	cout<<"\n\n\n\n\n\n\n\n\t\t\t\tENTER THE DETAILS OF THE DONOR";

	cout<<"\n\n\t\t\tNAME         : ";
	gets(name);

	cout<<"\n\t\t\tADDRESS ";

	cout<<"\n\t\t\t   HOUSE NO    : ";
	cin>>add.house_no;

	cout<<"\n\t\t\t   AREA        : ";
	gets(add.area);

	cout<<"\n\t\t\t   CITY        : ";
	gets(add.city);

	cout<<"\n\t\t\tBLOOD GROUP    : ";
	gets(bloodg);


   }






void bloodbank::outputdata()
  {
      cout<<"\n\n\n\n\n\n\n\n\n\t\t\tNAME        : ";
      cout<<name;

      cout<<"\n\t\t\tADDRESS ";

      cout<<"\n\t\t\t  HOUSE NO : ";
      cout<<add.house_no;

      cout<<"\n\t\t\t  AREA     : ";
      cout<<add.area;

      cout<<"\n\t\t\t  CITY     : ";
      cout<<add.city;

      cout<<"\n\t\t\tBLOOD GROUP : ";
      cout<<bloodg;

  }





void bloodbank::adddonor()
    {


       ofstream fout1;
       fout1.open("donor.txt",ios::binary|ios::app);
       bb.inputdata();
       fout1.write((char*)&bb,sizeof(bb));

       fout1.close();


   }


void search(char *bg)

   {

	cleardevice();
	clrscr();
	font();


	ifstream fin1("donor.txt",ios::binary|ios::out);

	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tLIST OF DONORS\n\n\n";


	while(!fin1.eof())
	    {

	      fin1.read((char*)&bb,sizeof(bb));

	      if(fin1.eof())
	      break;


	      if(strcmpi(bb.getbb(),bg)==0)
	      cout<<"                   "<<bb.getname()<<endl;


	    }


  fin1.close();
  getch();

    }





void blood_fun()
    {

       int ch1;
       label3:

       cleardevice();
       clrscr();
       font();


       cout<<"\n\n\n\n\n\n\n\n\n\t\t1.CREATE A NEW ACCOUNT OF DONOR\n\n";
       cout<<"\t\t2.CHECK THE AVAILABILITY OF BLOOD DONORS\n\n";
       cout<<"\t\t3.BACK TO MAIN MENU\n\n";
       cout<<"\t\t4.EXIT\n\n";
       cout<<"\t\tENTER YOUR CHOICE\t";

  cin>>ch1;


  switch(ch1)
     {

	 case 1:

		cleardevice();
		clrscr();
		font();

		bb.adddonor();
		getch();
		goto label3;


	 case 2:

		 char bg[4],c;
		 label1:
		 cleardevice();
		 clrscr();
		 font();

		 cout<<"\n\n\n\n\n\n\n\n\t\t\tENTER THE REQUIRED BLOOD GROUP\n";
		 cout<<"\t\t\t* A+"<<endl<<"\t\t\t* B+"<<endl<<"\t\t\t* AB+"<<endl<<"\t\t\t* O+"<<endl<<"\t\t\t* AB-"<<endl<<"\t\t\t* O-"<<endl<<"\t\t\t* B-"<<endl<<"\t\t\t* A-"<<endl;
		 cout<<endl<<"\t\t\t";
		 cin>>bg;


		 if(strcmpi(bg,"A+")==0||strcmpi(bg,"B+")==0||strcmpi(bg,"AB+")==0||strcmpi(bg,"O+")==0)
		     {


		       cout<<"\n\t\t\tAVAILABLE..!!\n";
		       getch();
		       search(bg);


		     }


		     else if(strcmpi(bg,"A-")==0||strcmpi(bg,"B-")==0||strcmpi(bg,"AB-")==0||strcmpi(bg,"O-")==0)
			{


			  cout<<"\n\t\t\tNOT AVAILABLE..!!\n";

			  cout<<"\n\t\tDO YOU WANT TO CHECK THE AVAILABILITY AGAIN?\n\t\t\t\t";
			  cin>>c;



			      if(c=='y'||c=='Y')
				goto label1;


			}

		     else


			{


			     cout<<"\n\n\n\n\n\t\t\tENTER AGAIN\n";
			     getch();
			     goto label1;

			}

    case 3:

	    menu();
	    break;

    case 4:
	    exit(0);
	    break;


    default:

	     cout<<"\n\t\t\t\tINVALID CHOICE..!!\n\n";
	     cout<<"\a";
	     cout<<"\t\t\t\tENTER AGAIN";
	     getch();
	     goto label3;


  }


}




/*--------------------------------------------------------------------------

			HEALTH CAMP STARTS

---------------------------------------------------------------------------*/



void funrandom()
{
    int randdoc;

    randomize();

    ifstream finr("doctor.txt",ios::binary|ios::in);

    randdoc=random(5);

    while(!finr.eof())
     {
	 finr.read((char*)&doc,sizeof(doc));

	 if(finr.eof())
	 break;

	 if(doc.getid()==randdoc)
	 cout<<doc.getname();

     }

    finr.close();

}



void healthcamps()
{
    int citych;
    char exithch;

    label9:
    cleardevice();
    clrscr();
    font();

    cout<<"\n\n\n\n\n\n\n\n\t\t\tLIST OF HEALHCAMPS IN KARNATAKA\n\n";
    cout<<"\t\t\t  1.RAMNAGAR\n\n";
    cout<<"\t\t\t  2.GULBARGA\n\n";
    cout<<"\t\t\t  3.RAICHUR\n\n";
    cout<<"\t\t\t  4.SHIMOGA\n\n";
    cout<<"\t\t\t  5.KOLAR\n\n";
    cout<<"\t\t\t  6.GO TO PREVIOUS MENU\n\n";
    cout<<"\t\t\t  7.EXIT\n\n";
    cout<<"\t\t\tCHOOSE THE CITY:   ";
    cin>>citych;
    switch(citych)
     {
	 case 1:
		 cleardevice();
		 clrscr();
		 font();

		 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tRAMNAGAR\n\n";
		 cout<<"\t\tSTATUS: ONGOING\n\n";
		 cout<<"\t\tNO OF PATIENTS CURED: 390 AND COUNTING\n\n";
		 cout<<"\t\tMAJOR PROBLEM DETECTED: DENGUE\n\n";
		 cout<<"\t\tDOCTOR SUPERVISING: ";
		 funrandom();
		 getch();

		 goto label9;

	 case 2:
		 cleardevice();
		 clrscr();
		 font();

		 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tGULBARGA\n\n";
		 cout<<"\t\tSTATUS: FINISHED\n\n";
		 cout<<"\t\tNO OF PATIENTS CURED: 250\n\n";
		 cout<<"\t\tAJOR PROBLEM DETECTED: CHICKENPOX \n\n";
		 cout<<"\t\tDOCTOR SUPERVISED : ";
		 funrandom();
		 getch();

		 goto label9;


	case 3:
		 cleardevice();
		 clrscr();
		 font();

		 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tRAICHUR\n\n";
		 cout<<"\t\tSTATUS: ONGOING\n\n";
		 cout<<"\t\tNO OF PATIENTS CURED: 550 AND COUNTING\n\n";
		 cout<<"\t\tMAJOR PROBLEM DETECTED: TYPHOID \n\n";
		 cout<<"\t\tDOCTOR SUPERVISED : ";
		 funrandom();
		 getch();

		 goto label9;

	case 4:
		 cleardevice();
		 clrscr();
		 font();

		 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tKARWAR\n\n";
		 cout<<"\t\tSTATUS: STARTING FROM DECEMBER 3\n\n";
		 cout<<"\t\tNO OF PATIENTS CURED: \n\n";
		 cout<<"\t\tMAJOR PROBLEM DETECTED: FOOD POISONING \n\n";
		 cout<<"\t\tDOCTOR SUPERVISED : ";
		 funrandom();
		 getch();

		 goto label9;

	case 5:
		 cleardevice();
		 clrscr();
		 font();

		 cout<<"\n\n\n\n\n\n\n\n\t\t\t\tKOLAR\n\n";
		 cout<<"\t\tSTATUS: ONGOING\n\n";
		 cout<<"\t\tNO OF PATIENTS CURED: 600\n\n";
		 cout<<"\t\tMAJOR PROBLEM DETECTED: BRONCHITIS \n\n";
		 cout<<"\t\tDOCTOR SUPERVISED : ";
		 funrandom();
		 getch();

		 goto label9;

	case 6:
		 menu();

		 break;

	case 7:
		 cout<<"\n\t\t\t ARE YOU SURE YOU WANT TO EXIT?? ( Y / N)\n\t\t\t\t";
		 cin>>exithch;

		 if(exithch=='Y'||exithch=='y')
		  {
		      getch();
		      exit(0);

		  }

		    else
		       goto label9;

       default:
		 cout<<"\t\t\t\tINVALID CHOICE...!! \n";
		 cout<<"\a";
		 getch();

		 goto label9;

     }

}




/* ----------------------------------------------------------------------
			     MAIN MENU STARTS
   ---------------------------------------------------------------------*/

void menu()
{
    int choice1;
    char ch,ch1,exitch,password[11];

    label:
    cleardevice();
    clrscr();

    setbkcolor(BROWN);                   // BACKGROUND COLOUR
    font();

    polygon();
    font();


    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t    HOME\n\n";
    cout<<"\n\t\t\t\t1.RECEPTION\n\n";
    cout<<"\t\t\t\t2.ADMINISTRATOR\n\n";
    cout<<"\t\t\t\t3.BLOOD BANK\n\n";
    cout<<"\t\t\t\t4.HEALTH CAMPS\n\n";
    cout<<"\t\t\t\t5.EXIT\n\n";

    cout<<"\n\t\t\tENTER YOUR CHOICE\t";

    cin>>choice1;

    switch(choice1)
     {

	  case 1:
		  label2 :
		  cleardevice();
		  clrscr();
		  font();

		  receptionist();

		  break;

	  case 2:
		  do
		  {
		      cleardevice();
		      clrscr();
		      font();

		      cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t  LOGIN";
		      cout<<"\n\n\n\t\tENTER THE ADMINISTRATION PASSWORD : ";

		      for(int f=0;f<5;f++)
			 {
			     char c=getch();
			     cout<<"*";
			     password[f]=c;

			 }
		       password[5]='\0';
		       getch();
		      if(strcmp(password,"cutis\0")==0)
		       {
			    cleardevice();
			    clrscr();
			    settextstyle(1,0,1);
			    outtextxy(49,369,"SIGNING IN....");

			    for(int j=0;j<220;j++)
				{
				     rectangle(400+j,400,20+j,401);
				     delay(20);

				}

			    cleardevice();
			    clrscr();
			    font();

			    admin();

		       }

			else
			   cout<<"\n\n\n\t\t\t   WRONG PASSWORD...!!!\n\n";

		      cout<<"\t\t    WANT TO ENTER AGAIN..?? ( Y / N) \n\t\t\t";
		      cin>>ch1;

		  }
		  while(ch1=='y'||ch1=='Y');

		  if(ch1!='y'||ch1!='Y')
		    {
			 cleardevice;
			 clrscr();
			 font();
			 goto label;

		    }

	  case 3:
		   cleardevice();
		   clrscr();
		   font();

		   blood_fun();

		   break;

	  case 4:
		   cleardevice();
		   clrscr();
		   font();

		   healthcamps();

		   break;

	  case 5:

		   cout<<"\n\t\t\tARE YOU SURE YOU WANT TO EXIT?(Y/N)\n\t\t\t";
		   cin>>exitch;
		   if(exitch=='Y'||exitch=='y')
		    {
			 getch();
			 exit(0);

		    }
		     else

		       goto label;

	 default:
		   cout<<"\n\t\t\tINVALID CHOICE...!!!";
		    cout<<"\a";
		   getch();

		   cleardevice();
		   clrscr();
		   font();

		   goto label;

     }

}



void main()
{
    /* request auto detection */
       int gdriver = DETECT, gmode, errorcode;
       int left, top, right, bottom;

    /* initialize graphics and local variables */
       initgraph(&gdriver, &gmode, "");

    /* read result of initialization */
       errorcode = graphresult();
       if (errorcode != grOk)  /* an error occurred */
	{
	   printf("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf("Press any key to halt:");
	   getch();
	   exit(1); /* terminate with an error code */

	}

       setbkcolor(15);
       setfillstyle(CLOSE_DOT_FILL,BLUE);
       floodfill(2,2,RED);
       setfillstyle(SOLID_FILL,RED);
       bar(330,175,295,400);
       bar(213,300,415,260);

       setcolor(EGA_BLUE);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
       outtextxy(70,40,"CUTIS HOSPITAL");
       getch();

       cleardevice();

       menu();

       getch();
       cleardevice();
       closegraph();
}
