/***********************************************************************************************************************************************/
    #include<iostream>
    #include<fstream>
    #include<windows.h>
 
    using namespace std;
    /****************************************************************************************
    *  Variables:                                                                           *
    *  1.int:                                                                               *
    *       id for user id cin and tid for id in which user want to send money              *
    *       pin,p for pin cin,cpin for current pin,npin for new pin and cnpin for confrm pin*
    *       z,h recive return value form functions for different account                    *
    *       bal which save balance of the user and amou which is online transaction amount  *
    *       widra save amount which user want to withdraw                                   *
    *       deposit save amount which user want to deposit                                  *
	*       fast for fast cash option                                                       *
    *  2.char:                                                                              *
    *        x whih use to proceed                                                          *
    *        choice which use to use menu                                                   *
    *        splip genrate slip                                                             *
    *        futr use to make another transection                                           *
    *****************************************************************************************/         
    int id,tid,pin,npin,cpin,cnpin,p,z,h,bal,nbal,tbal,widra,deposit,amou,fast;
    char x,choice,slip,futr;
    /****************************************************************************************
    *   functions:                                                                          *
    *   1.menu function print menu                                                          *
    *   2.cashwid and cashdeposit withraw and deposit cash in user account                  *
    *   3.info function read user information and from there accounts                       *
    *   4.write function overwrite user information                                         *
    *   5.ontra and ontrawrite for online transection                                       *
    *   6.fastcash                                                                          *
    *****************************************************************************************/ 
	 
    void menu();
    void cashdeposit(int &deposit);
    void cashwid(int &widra);
    int info(int &bal);
	void write();
	void ontra(int &amou);
	void ontrawrite(int &tbal);
	void fastcash();
	int reset();
    int main()
    {
        do
        {
        	system("cls");
        	system("color f0");
        	cout<<"\n\n\t\t\t\tPROJECT ";Sleep(300);cout<<"BY ";Sleep(300);cout<<"HAMAS ";Sleep(300);cout<<"AND ";Sleep(300);cout<<"AZIB !!!";
        	Sleep(1000);
            cout<<"\n\n\n\n\t\t\t\tThank";Sleep(300);cout<<" You";Sleep(300);cout<<" For";Sleep(300);cout<<" Banking";Sleep(300);cout<<" With";Sleep(300);cout<<" Us"<<endl;
            
            Sleep(2000);
	        cout<<"\n\n\n\t\t\t\tEnter your credit card"<<endl;
	        cout<<"\n\n\n\t\t\t\tEnter your six digit id : "<<endl;
	        cout<<"\n\t\t\t\t\t\t***********************\n\n";
			cout<<"\t\t\t\t\t\t\t";cin>>id;
			cout<<"\n\t\t\t\t\t\t***********************";
	        ifstream infile;
	        infile.open("acc.txt");
	        int Azib,Hamas;
	        infile>>Azib>>Hamas;
	        while(id!=Azib && id!=Hamas&&id!=0000)
	        {
		        cout<<"\n\n\n\t\t\t\tThis id don't exsit";
		        cout<<"\n\n\n\t\t\t\tEnter your six digit id: ";
	            cin>>id;
	        }
	        cout<<"\n\n\n\t\t\t\tAfter entering id press y to continue : ";
	        cin>>x;
	        if(x=='R')
	        {
	        	reset();
	        	break;
			}
	        while(x!='y')
	        {
	            cout<<"\n\n\n\t\t\t\tInvalid input";
	            cout<<"\n\n\n\t\t\t\tAfter entering id press y to continue : ";
	            cin>>x;	
	        }
	        system("cls");
	        system("color 17");
            switch(id)
            {
    	        case 123456:
    		    z=info(bal);
    	        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter your pin : "<<endl;
	            cout<<"\t\t\t\t\t\t   ";cin>>pin;
	            Sleep(1000);
	            for(int i=1;i<=3;i++)
	            {
	            	system("cls");
	        	    if(z==pin)
	        	    break;
	        	    system("color 4f");
	        	    if(z!=pin&&i<3)
	        	    {
	        	    	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tIncorrect pin !";
    	                cout<<"\n\t\t\t\t\t\tEnter your pin : "<<endl;
	                    cout<<"\t\t\t\t\t\t   ";cin>>pin;
				    }
				    if(i==3)
			        {
			    	    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tYour account is not accessible at the moment try again later !\n\n";
			    	    cout<<"\t\t\t\t";system("pause");
				    }
			    }
			    if(z!=pin)
			    break;
			    system("color 17");
			    do
			    {
				    system("cls");
				    system("color 70");
			        menu();
			        cout<<"\n\n\n\t\t\t\tEnter your choice: ";
			        cin>>choice;
			        if(choice=='g')
			        break;
			        switch(choice)
			        {
				        case'a':
				        	system("color 8f");
					        cout<<"\n\n\n\t\t\t\tYour current balance is : "<<bal<<" $";
					        break;
				        case'b':
				        	system("color 8f");
					        cout<<"\n\n\n\t\t\t\tEnter the amount which you want to withdraw"<<endl;
	                        cout<<"\n\t\t\t\t\t\t***********************\n\n";
			                cout<<"\t\t\t\t\t\t\t";cin>>widra;
			                cout<<"\n\t\t\t\t\t\t***********************";
					        while(bal<widra)
                            {
		                        cout<<"\n\n\n\t\t\t\tWithdraw amount is greater then your balance Which is : "<<bal;
		                        cout<<"\n\n\tEnter the correct amount to withdraw"<<endl;
	                            cout<<"\n\t\t\t\t\t\t***********************\n\n";
			                    cout<<"\t\t\t\t\t\t\t";cin>>widra;
			                    cout<<"\n\t\t\t\t\t\t***********************";
	                        }
	                        cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
	                        cout<<"\n\n\n\t\t\t\tDo you want slip y/n : ";
	                        cin>>slip;
					        cashwid(widra);
					        if(slip=='y')
					        {
					        	cout<<"\n\tt\t\t\t*****************************";
						        cout<<"\n\t\t\t\t* Transaction Amount: "<<widra<<"    *";
						        cout<<"\n\t\t\t\t* Available Balance: "<<bal<<" *";
						        cout<<"\n\t\t\t\t* Available Limit: 50000"<<"    *";
						        cout<<"\n\t\t\t\t*****************************";
					        }
					        else
					        break;
					        break;
			            case 'c':
			            	system("color 8f");
			    	        cout<<"\n\n\tEnter the amount which you want to deposit"<<endl;
	                        cout<<"\n\t\t\t\t\t\t***********************\n\n";
			                cout<<"\t\t\t\t\t\t\t";cin>>deposit;
			                cout<<"\n\t\t\t\t\t\t***********************";
			                cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
					        cout<<"\n\n\n\t\t\t\tSuccessfuly deposited";
					        cashdeposit(deposit);
					        cout<<"\n\n\n\t\t\t\tDo you want slip y/n : ";
	                        cin>>slip;
					        cashdeposit(deposit);
					        if(slip=='y')
					        {
					        	cout<<"\n\t\t\t\t*****************************";
						        cout<<"\n\t\t\t\t* Deposited Amount: "<<deposit<<"      *";
						        cout<<"\n\t\t\t\t* Available Balance: "<<bal<<" *";
						        cout<<"\n\t\t\t\t*****************************";
					        }
					        break;
				        case 'd':
				        	system("color 8f");
				            cout<<"\n\n\n\t\t\t\tTo change pin first enter your current pin : ";
					        cin>>cpin;
					        while(cpin!=pin)
					        {
						        cout<<"\n\n\n\t\t\t\tIncorrect";
						        cout<<"\n\n\n\t\t\t\tEnter your current pin : ";
					            cin>>cpin;
					        }
					        cout<<"\n\n\n\t\t\t\tEnter your new pin : ";
					        cin>>npin;
					        while(cpin==npin)
					        {
						        cout<<"\n\n\n\t\t\t\tYour new pin is same as current pin";
						        cout<<"\n\n\n\t\t\t\tEnter your new pin : ";
					            cin>>npin;
					        }
					        cout<<"\n\n\n\t\t\t\tConfirm your pin : ";
					        cin>>cnpin;
					        while(cnpin!=npin)
					        {
						        cout<<"\n\n\n\t\t\t\tIncorrect";
						        cout<<"\n\n\n\t\t\t\tConfirm your pin : ";
					            cin>>cnpin;
					        }
					        pin=cnpin;
					        write();
					        break;
					    case 'e':
					    	system("color 8f");
						    cout<<"\n\n\n\t\t\t\tEnter the id to which you want to send money : ";
							cin>>tid;
							if(tid==123456)
								{
									cout<<"\n\n\n\t\t\t\tIts your own id !";
								    cout<<"\n\n\n\t\t\t\tEnter the id to which you want to send money : ";
							        cin>>tid;
								}
							while(tid!=123457)
							{
								
								cout<<"\n\n\n\t\t\t\tId don't exist' !";
								cout<<"\n\n\n\t\t\t\tEnter the id to which you want to send money : ";
							    cin>>tid;
								
							}
							cout<<"\n\n\n\t\t\t\tEnter the amount you want to transfer : ";
							cin>>amou;
							while(amou>bal)
							{
								cout<<"\n\n\n\t\t\t\tEnterd amount is greater then your current balance";
								cout<<"\n\n\n\t\t\t\tEnter the amount you want to transfer : ";
							    cin>>amou;
							}
							bal=bal-amou;
							write();
							ontra(amou);
							cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
							cout<<"\n\n\n\t\t\t\tSuccesfuly transferd !";
							break;
						case 'f':
							system("color 8f");
							system("cls");
						    cout<<"\n\n\n\t\t\t\tFast cash !. Select the option : \n";
							fastcash();
							cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
							cout<<"\n\n\n\t\t\t\tDo you want slip y/n : ";
	                        cin>>slip;
					        if(slip=='y')
					        {
					        	cout<<"\n\tt\t\t\t*****************************";
						        cout<<"\n\t\t\t\t* Available Balance: "<<bal<<" *";
						        cout<<"\n\t\t\t\t* Available Limit: 50000"<<"    *";
						        cout<<"\n\t\t\t\t*****************************";
					        }
					        else
	                        break;
				    }
			        cout<<"\n\n\n\t\tDo you want further transaction y/n : ";
			        cin>>futr;
			        while(futr!='y'&&futr!='n')
			        {
			            cout<<"\n\n\n\t\t\t\tDo you want further transaction y/n : ";
			            cin>>futr;
			        }
		        }
		        while(futr!='n');
	            break;
	            case 123457:
                h=info(bal);
                cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter your pin : "<<endl;
	            cout<<"\t\t\t\t\t\t   ";cin>>pin;
	            for(int i=1;i<=3;i++)
	            {
	            	system("cls");
	        	    if(h==pin)
	        	    break;
	        	    system("color 4f");
	        	    if(h!=pin&&i<3)
	        	    {
                        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tIncorrect pin !";
    	                cout<<"\n\t\t\t\t\t\tEnter your pin : "<<endl;
	                    cout<<"\t\t\t\t\t\t   ";cin>>pin;
				    }
				    if(i==3)
			        {
			    	    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tYour account is not accessible at the moment try again later !\n\n";
			    	    cout<<"\t\t\t\t";system("pause");
				    }
			    }
			    if(h!=pin)
			    break;
			    system("color 17");
			    do
			    {
				    system("cls");
				    system("color 70");
			        menu();
			        cout<<"\n\n\n\t\t\t\tEnter your choice : ";
			        cin>>choice;
			        if(choice=='g')
			        break;
			        switch(choice)
			        {
					    case'a':
					    	system("color 8f");
					        cout<<"\n\n\n\t\t\t\tYour current balance is : "<<bal<<" $";
					        break;
				        case'b':
				        	system("color 8f");
				            cout<<"\n\n\n\t\t\t\tEnter the amount which you want to withdraw"<<endl;
	                        cout<<"\n\t\t\t\t\t\t***********************\n\n";
			                cout<<"\t\t\t\t\t\t\t";cin>>widra;
			                cout<<"\n\t\t\t\t\t\t***********************";
					        while(bal<widra)
                            {
		                        cout<<"\n\n\tWithdraw amount is greater then your balance Which is : "<<bal;
		                        cout<<"\n\n\tEnter the correct amount to withdraw"<<endl;
	                            cout<<"\n\t\t\t\t\t\t***********************\n\n";
			                    cout<<"\t\t\t\t\t\t\t";cin>>widra;
			                    cout<<"\n\t\t\t\t\t\t***********************";
	                        }
	                        cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
	                        cout<<"\n\n\n\t\t\t\tDo you want slip y/n : ";
	                        cin>>slip;
					        cashwid(widra);
					        if(slip=='y')
					        {
						        cout<<"\n\tt\t\t\t*****************************";
						        cout<<"\n\t\t\t\t* Transaction Amount: "<<widra<<"    *";
						        cout<<"\n\t\t\t\t* Available Balance: "<<bal<<" *";
						        cout<<"\n\t\t\t\t* Available Limit: 50000"<<"    *";
						        cout<<"\n\t\t\t\t*****************************";
					        }
					        else
					        break;
					        break;
			            case 'c':
			            	system("color 8f");
			    	        cout<<"\n\n\tEnter the amount which you want to deposit"<<endl;
			    	        cout<<"\n\t\t\t\t\t\t***********************\n\n";
			                cout<<"\t\t\t\t\t\t\t";cin>>deposit;
			                cout<<"\n\t\t\t\t\t\t***********************";
					    
					        cout<<"\n\n\tSuccessfuly deposited";
					        cashdeposit(deposit);
					        cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
					        cout<<"\n\n\n\t\t\t\tDo you want slip y/n : ";
	                        cin>>slip;
					        cashdeposit(deposit);
					        if(slip=='y')
					        {
						        cout<<"\n\t\t\t\t*************************************";
						        cout<<"\n\t\t\t\t* Deposited Amount: "<<deposit<<"      *";
						        cout<<"\n\t\t\t\t* Available Balance: "<<bal<<" *";
						        cout<<"\n\t\t\t\t*****************************";
					        }
					        break;
				        case 'd':
				        	system("color 8f");
				            cout<<"\n\n\n\t\t\t\tTo change pin first enter your current pin : ";
					        cin>>cpin;
					        while(cpin!=pin)
					        {
						        cout<<"\n\n\n\t\t\t\tIncorrect";
						        cout<<"\n\n\n\t\t\t\tEnter your current pin : ";
					            cin>>cpin;
					        }
					        cout<<"\n\n\n\t\t\t\tEnter your new pin : ";
					        cin>>npin;
					        while(cpin==npin)
					        {
						        cout<<"\n\n\n\t\t\t\tYour new pin is same as current pin";
						        cout<<"\n\n\n\t\t\t\tEnter your new pin : ";
					            cin>>npin;
					        }
					        cout<<"\n\n\n\t\t\t\tConfirm your pin : ";
					        cin>>cnpin;
					        while(cnpin!=npin)
					        {
						        cout<<"\n\n\n\t\t\t\tIncorrect";
						        cout<<"\n\n\n\t\t\t\tConfirm your pin : ";
					            cin>>cnpin;
					        }
					        pin=cnpin;
					        write();
					        break;
					    case 'e':
					    	system("color 8f");
						    cout<<"\n\n\n\t\t\t\tEnter the id to which you want to send money : ";
							cin>>tid;
							if(tid==123457)
								{
									cout<<"\n\n\n\t\t\t\tIts your own id !";
								    cout<<"\n\n\n\t\t\t\tEnter the id to which you want to send money : ";
							        cin>>tid;
								}
							while(tid!=123456)
							{
								
								cout<<"\n\n\n\t\t\t\tId don't exist' !";
								cout<<"\n\n\n\t\t\t\tEnter the id to which you want to send money : ";
							    cin>>tid;
								
							}
							cout<<"\n\n\n\t\t\t\tEnter the amount you want to transfer : ";
							cin>>amou;
							while(amou>bal)
							{
								cout<<"\n\n\n\t\t\t\tEnterd amount is greater then your current balance";
								cout<<"\n\n\n\t\t\t\tEnter the amount you want to transfer : ";
							    cin>>amou;
							}
							bal=bal-amou;
							write();
							ontra(amou);
							cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
							cout<<"\n\n\n\t\t\t\tSuccesfuly transferd !";
							break;
						case 'f':
							system("color 8f");
							system("cls");
						    cout<<"\n\n\n\t\t\t\tFast cash !. Select the option : \n";
							fastcash();
							cout<<"\n\n\n\t\t\t\tProcessing";Sleep(500);cout<<" .";Sleep(500);cout<<" .";Sleep(500);cout<<" .";
							cout<<"\n\n\n\t\t\t\tDo you want slip y/n : ";
	                        cin>>slip;
					        if(slip=='y')
					        {
					        	cout<<"\n\tt\t\t\t*****************************";
						        cout<<"\n\t\t\t\t* Available Balance: "<<bal<<" *";
						        cout<<"\n\t\t\t\t* Available Limit: 50000"<<"    *";
						        cout<<"\n\t\t\t\t*****************************";
					        }
					        else
	                        break;   
			        }
			        cout<<"\n\n\n\t\t\t\tDo you want further transaction y/n : ";
			        cin>>futr;
			        while(futr!='y'&&futr!='n')
			        {
			            cout<<"\n\n\n\t\t\t\tDo you want further transaction y/n : ";
			            cin>>futr;
			        }
		        }
		        while(futr!='n');
	            break;
	        }
        }
		while(1);
    }
/*********************************************************************************************************
*                                              ALL FUNCTIONS                                                             *
*********************************************************************************************************/                         
    void menu() 
    {   
    	cout<<"\n\n\n\n\t\t\t\t*************************************************************";
    	cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*   A. Balance Inquiry"<<"\t\t\t"<<"B. Cash Withdraw    *";
	    cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*   C. Cash Deposit"<<"\t\t\t"<<"D. Password Change  *";
        cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*   E. Online Transaction"<<"\t\t"<<"F. Fast cash        *";
        cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*\t\t\t   G. Exit\t\t\t    *";
	    cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*************************************************************";
    }
    void cashwid(int &widra)
    {
        bal=bal-widra;
        write();
    }
    void cashdeposit(int &deposit)
    {

	    bal=bal+deposit;
        write();
    }
    int info(int &bal)
    {
	    int ret;
	    if(id==123456)
	    {
	    	ifstream infile;
	        infile.open("psazib.txt");
	        int psazib,balazib;
	        infile>>psazib;
	        infile>>balazib;
	        bal=balazib;
	        ret=psazib;
	        return ret;	
		}
		if(id==123457)
		{
			ifstream infile;
	        infile.open("pshamas.txt");
	        int pshamas,balhamas;
	        infile>>pshamas;
	        infile>>balhamas;
	        bal=balhamas;
	        ret=pshamas;
	        return ret;	
		}
    }
    void write()
    {
    	if(id==123456)
    	{
    	    ofstream azib("psazib.txt");
	        int psazib,balazib;
	        psazib=pin;
            balazib=bal;
            azib<<psazib<<endl;
	        azib<<balazib; 
		}
		if(id==123457)
		{
			ofstream azib("pshamas.txt");
	        int pshamas,balhamas;
	        pshamas=pin;
            balhamas=bal;
            azib<<pshamas<<endl;
	        azib<<balhamas;	
		}
    }

    void ontra(int &amou)
    {
    	if(tid==123456)
    	{
	        ifstream infile;
	        infile.open("psazib.txt");
	        int psazib,balazib;
	        infile>>psazib;
	        infile>>balazib;
	        nbal=balazib;
	        p=psazib;
	        tbal=nbal+amou;
	        ontrawrite(tbal);
		}
		    	if(tid==123457)
    	{
	        ifstream infile;
	        infile.open("pshamas.txt");
	        int pshamas,balhamas;
	        infile>>pshamas;
	        infile>>balhamas;
	        nbal=balhamas;
	        p=pshamas;
	        tbal=nbal+amou;
	        ontrawrite(tbal);
		}
	}
	void ontrawrite(int &tbal)
	{
		if(tid==123456)
		{
			
			ofstream azib("psazib.txt");
	        int psazib,balazib;
	        psazib=p;
            balazib=tbal;
            azib<<psazib<<endl;
	        azib<<balazib; 
		}
		if(tid==123457)
		{
			
			ofstream azib("pshamas.txt");
	        int pshamas,balhamas;
	        pshamas=p;
            balhamas=tbal;
            azib<<pshamas<<endl;
	        azib<<balhamas; 
		}
	}
    void fastcash()
	{
		cout<<"\n\n\t\t\t\t*************************************************************";
    	cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*   1.      500       "<<"\t\t\t"<<"2.    1000          *";
	    cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*   3.      5000       "<<"\t\t\t"<<"4.    10000         *";
        cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*   5.      15000     "<<"\t\t\t"<<"6.    25000         *";
        cout<<"\n\t\t\t\t*                                                           *";
        cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*\t\t\t   7. Exit\t\t\t    *";
	    cout<<"\n\t\t\t\t*                                                           *";
	    cout<<"\n\t\t\t\t*************************************************************";
		cout<<"\n\n\t\t\t\tEnter the option : ";
		cin>>fast;
		if(id==123456)
		{
			switch(fast)
			{
				case 1:
					bal=bal-500;
					write();
					break;
				case 2:
					bal=bal-1000;
					write();
					break;
				case 3:
					bal=bal-5000;
					write();
					break;
				case 4:
					bal=bal-10000;
					write();
					break;
				case 5:
					bal=bal-15000;
					write();
					break;
				case 6:
					bal=bal-25000;
					write();
					break;
				case 7:
					break;
			}
		}
		if(id==123457)
		{
			switch(fast)
			{
				case 1:
					bal=bal-500;
					write();
					break;
				case 2:
					bal=bal-1000;
					write();
					break;
				case 3:
					bal=bal-5000;
					write();
					break;
				case 4:
					bal=bal-10000;
					write();
					break;
				case 5:
					bal=bal-15000;
					write();
					break;
				case 6:
					bal=bal-25000;
					write();
					break;
				case 7:
					break;
			}
		}
		
	}
	int reset()
	{
		int rp=0000;
		cout<<"\n\n\t\t\t\tEnter reset pin : ";
		cin>>rp;
		if(rp!=0000)
		{
			return 0;
		}
		if(rp==0000)
		{
		    ofstream ids("acc.txt");
	        int Azib,Hamas;
	        Azib=123456;
	        Hamas=123457;
	        ids<<Azib<<endl<<Hamas;
	        /*********************/
	        ofstream azib("psazib.txt");
            int psazib,balazib;
	        psazib=123456;
            balazib=10000;
            azib<<psazib<<endl;
	        azib<<balazib;
	        /*********************/
	        ofstream hamas("pshamas.txt");
            int pshamas,balhamas;
	        pshamas=123457;
            balhamas=10000;
            hamas<<pshamas<<endl;
	        hamas<<balhamas;
		}
	}
/***********************************************************************************************************************************************/
