#include <iostream>
#include <fstream>

using namespace std;

//Goods details array
int quantity[256];
string UPC_code[256];
string Goods_name[256];
string Goods_Brand[256];
//Supplier details array
string Supplier_name[256];
string Phone_number[256];
string Supplier_Brand[256];

//Functions prototypes
void Introduction();
void Add_New_Goods();
void Add_New_Supplier();
void Search();
void Goods_Report();
void Supplier_Report();
void Update();
void Delete_Goods_Record();
void Delete_Supplier_Record();

int main()
{
    Introduction();
    char choice;
	char report;
	char delet;
    do
    {
		system("cls"); //clear screen command using system function we will use it as design only.
		string space = "\n\t";
		// the main face or the hme page for the programm.
		cout << space << "[1] Add new product." << endl;
		cout << space << "[2] Add new supplier." << endl;
		cout << space << "[3] Sreach goods details." << endl;
		cout << space << "[4] Reports ( goods or supplier )." << endl;
		cout << space << "[5] Update goods information." << endl;
		cout << space << "[6] Delete goods or supplier record." << endl;
		cout << space << "[7] Exit the system." << endl;
		cin >> choice; // taking the user choise.
		switch(choice)
		{
			case '1':
				Add_New_Goods();
				break;
			case '2':
				Add_New_Supplier();
				break;
			case '3':
				Search();
				break;
			case '4':
				system("cls");
				cout << endl << "\t[1] Goods Report." << endl << "\n\t[2] Supplier Report." << endl;
				cin >> report;
				switch(report)
				{
					case '1':
						Goods_Report();
						break;
					case '2':
						Supplier_Report();
						break;
					default:
					cout << "invaild choice." << endl;
				}
				break;
			case '5':
				Update();
				break;
			case '6':
				system("cls");
				cout << endl << "\t Which Record you want to delete from ? " << endl << endl;
				cout << "\t [1] Delete Goods Record." << endl << endl << "\t [2] Delete Supplier Record." << endl << endl;
				cin >> delet;
				switch(delet)
				{
					case '1':
						Delete_Goods_Record();
						break;
					case '2':
						Delete_Supplier_Record();
						break;
					default:
						cout << "Wrong input.";
				}
				break;
			case '7':
				system("cls");
				cout << "\n\tThank you for using\n\n\tSUPER MARKET MANAGEMENT SYSTEM\n\n\tsee you soon!\n\n\n\n\tCreated by: Ali Almuhaysin - Hamad Aljagtham - Hussain Almarzooq";
				break;
			default:
				cout << "Wrong input!!" << endl;
				cout << "Press ENTER to continue...";
		}
		
		cin.get();
    } while (choice != '7');
    
    return 0;
}

void Add_New_Goods()
{
	int i = 0;
	system("cls");
	cout << endl << "\t\t|    Add new product    |" << endl;
	cout << endl << "    Enter Product's name (Please use \"_\" instead of SPACE) :  ";
    cin >> Goods_name[i];

    cout << endl << "    Enter CPU code :  ";
    cin >> UPC_code[i];
    
    cout << endl << "    Enter The quantity :  ";
    cin >> quantity[i];
    
    cout << endl << "    Enter Product's Brand (Please use \"_\" instead of SPACE) :  ";
    cin >> Goods_Brand[i];
    
    fstream GoodsFile;
    GoodsFile.open("GoodsFile.text", ios::app);
    if (GoodsFile.is_open())
    {
    	GoodsFile << Goods_name[i] << " " << UPC_code[i] << " " << quantity[i] << " " << Goods_Brand[i] << endl;
    	cout << endl << "    Product added successfully." << endl;
	}
	else
	{
		cout << "    Sorry!! A problem occurred while opening the file." << endl;
	}
	GoodsFile.close();
    cout << "    Press ENTER to continue ..." << endl;
    cin.get();

}

void Add_New_Supplier()
{
	system ("cls");
	int j = 0;
	cout << endl << "\t\t|    Add new supplier    |" << endl;
	cout << endl << "    Enter supplier name (Please use \"_\" instead of SPACE) :  ";
    cin >> Supplier_name[j];
   
    cout << "    Enter Supplier's phone number :  ";
    cin >> Phone_number[j] ; 
    
    cout << "    Enter Supplier's Brand (Please use \"_\" instead of SPACE) :  ";
    cin >> Supplier_Brand[j];
    
    fstream SupplierFile;
    SupplierFile.open("SupplierFile.text", ios::app);
    if (SupplierFile.is_open())
    {
    	SupplierFile << Supplier_name[j] << " " << Phone_number[j] << " " << Supplier_Brand[j] << endl;
		cout << endl << "    Supplier added successfully." << endl;   	
	}
	else
	{
		cout << "    Sorry!! A problem occurred while opening the file." << endl;
	}
	SupplierFile.close();
	cout << "    Press ENTER to continue...";
	cin.get();
}

void Search()
{
	system("cls");
	string UPC_search;
	string Brand_search;
	int num = 0;
	int upc_check = 1;
	cout << "\n    Please enter the UPC code for the product you want to sreach for : ";
	cin >> UPC_search;
	fstream InGoodsFile;
	InGoodsFile.open("GoodsFile.text");
	if (InGoodsFile.is_open())
	{
		while (!InGoodsFile.eof() && upc_check == 1)
		{
			InGoodsFile >> Goods_name[num] >> UPC_code[num] >> quantity[num] >> Goods_Brand[num];
			if (UPC_search == UPC_code[num])
			{
				cout << endl << "***********************************************" << endl;
				cout << "\t\t" << "Product Details : " << endl;
    			cout << "   Product Name : " << Goods_name[num] << "\t";
    			cout << "   UPC code : " << UPC_code[num] << "\t";
    			cout << "   Quantity : " << quantity[num] << "\t";
    			cout << endl << "***********************************************" << endl;
    			Brand_search = Goods_Brand[num];
    			upc_check = 0;
			}
			num++;
		}	
	}
	if (upc_check == 0)
	{
		num = 0;
		int check = 0;
		fstream InSupplierFile;
		InSupplierFile.open("SupplierFile.text");
		if (InSupplierFile.is_open())
		{
			while(!InSupplierFile.eof())
			{
				InSupplierFile >> Supplier_name[num] >> Phone_number[num] >> Supplier_Brand[num];
				if( Brand_search == Supplier_Brand[num] )
				{
					cout << endl << "***********************************************" << endl;
					cout << "\t\t" << "Supplier Details : " << endl;
    				cout << "   Supplier name : " << Supplier_name[num] << "\t";
    				cout << "   Supplier's phone number : " << Phone_number[num];
    				cout << endl << "***********************************************" << endl;
    				check = 1;
				}
				num++;
			}
			if (check == 0)
			{
				cout << endl << "***********************************************" << endl;
				cout << "\tThere is No Supplier record for this product.";
				cout << endl << "***********************************************" << endl;
			}
			cout << endl << "***********************************************" << endl;
    		cout << "   Brand : " << Brand_search;
    		cout << endl << "***********************************************" << endl;
		}
		else
		{
			cout << "    Sorry!! A problem occurred while opening the file." << endl;	
		}
		InSupplierFile.close();
	}
	else
	{
		cout << "    Product NOT found!!" << endl << "    Please check UPC code if it correct" << endl;
	}	
	cout << "    Press ENTER to continue...";
	cin.get();
}

void Goods_Report()
{
    system("cls");
    cout << "\n\t\tGoods List : " << endl;
    cout << endl << "***********************************************" << endl;
    int num = 0;
    int u;
    fstream InGoodsFile;
	InGoodsFile.open("GoodsFile.text");
	if (InGoodsFile.is_open())
	{
		while(!InGoodsFile.eof())
    	{
    		InGoodsFile >> Goods_name[num] >> UPC_code[num] >> quantity[num] >> Goods_Brand[num];
        	num++;
   		}
   		num--;
    	for (u = 0; u < num; u++)
    	{
    		cout << "    Product Name : " << Goods_name[u] << endl;
    		cout << "    UPC code : " << UPC_code[u] << endl;
    		cout << "    Quantity : " << quantity[u] << endl;
    		cout << "    Brand : " << Goods_Brand[u] << endl;
    		cout << endl << "***********************************************" << endl;
		}
	}
	else
	{
		cout << "    Sorry!! A problem occurred while opening the file." << endl;
	} 
	cout << "    Press ENTER to continue ... " << endl;
	cin.get();

}

void Supplier_Report()
{
    system("cls");
    cout << "\n\t\tSuppliers List : " << endl;
    cout << endl << "***********************************************" << endl;
    int num = 0;
    int u;
    fstream InSupplierFile;
	InSupplierFile.open("SupplierFile.text");
	if (InSupplierFile.is_open())
	{
		while(!InSupplierFile.eof())
    	{
    		InSupplierFile >> Supplier_name[num] >> Phone_number[num] >> Supplier_Brand[num];
        	num++;
   		 }
   		 num--;
    	for (u = 0; u < num; u++)
    	{
    		cout << "    Supplier name : " << Supplier_name[u] << endl;
    		cout << "    Supplier's phone number : " << Phone_number[u] << endl;
    		cout << "    Brand : " << Supplier_Brand[u] << endl;
    		cout << endl << "***********************************************" << endl;
		}
	}
	else
	{
		cout << "    Sorry!! A problem occurred while opening the file." << endl;
	} 
	cout << "    Press ENTER to continue ... " << endl;
	cin.get();

}

void Update()
{
	system("cls");
	fstream GoodsFile;
	fstream TempFile;
	fstream TempSFile;
	fstream SupplierFile;
	char update;
	cout << endl << "\tPlease choose which record you want to update : " << endl;
	cout << "\t[1] Goods records." << endl << "\t[2] Supplier records." << endl;
	cin >> update;
	system("cls");
	if (update == '1')
	{
		int j, c, d, t, i = 0;
		int check = 1;
		GoodsFile.open("GoodsFile.text");
		if (GoodsFile.is_open())
		{
			while(!GoodsFile.eof())
			{
				GoodsFile >> Goods_name[i] >> UPC_code[i] >> quantity[i] >> Goods_Brand[i];
				i++;
			}
			i--;
			cout << "\n    Please choose the product that you want to update By ID :" << endl << endl;
			for(j = 0; j < i ; j++)
			{
				cout << endl << "    ID : " << j << "\t";
				cout << "    Product name : " << Goods_name[j] << "\t";
				cout << "    UPC code : " << UPC_code[j] << "\t";
				cout << "    Quantity : " << quantity[j] << "\t";
				cout << "    Brand : " << Goods_Brand[j] << endl << endl;
			}
			cout << endl<< "    Enter Product ID to update it :";
			cin >> c;
			for (d = 0; d < j; d++)
			{
				if ( d == c )
				{
					check = 0;
				}
			}
			if (check == 0)
			{
				system("cls");
				cout << endl << "    The previous record : \n" << endl;
				cout << "    Product name : " << Goods_name[c] << "\t";
				cout << "    UPC code : " << UPC_code[c] << "\t";
				cout << "    Quantity : " << quantity[c] << "\t";
				cout << "    Brand : " << Goods_Brand[c] << endl;
				cout << endl << "*******************************************************************************" << endl;
				cout << endl << "    Please Enter The new record : \n" << endl;
				cout << "    Product name : ";
				cin >> Goods_name[c];
				cout << "    UPC code : ";
				cin >> UPC_code[c];
				cout << "    Quantity : ";
				cin >> quantity[c];
				cout << "    Brand : ";
				cin >> Goods_Brand[c];
				cout << endl << "*******************************************************************************" << endl;
				TempFile.open("Temp.text", ios::app);
				if (TempFile.is_open())
				{
					for(t = 0 ; t < i ; t++)
					{
						TempFile << Goods_name[t] << " " << UPC_code[t] << " " << quantity[t] << " " << Goods_Brand[t] << endl;
					}
					GoodsFile.close();
					TempFile.close();
					remove("GoodsFile.text");
					rename("Temp.text","GoodsFile.text");
					cout << endl << "\t Record was updated successfully." << endl;
				}
				else
				{
					cout << "    Sorry!! A problem occurred while opening the file." << endl;
				}
			}
			else
			{
				cout << "    Wrong input !! Please be sure that you have choose a correct ID." << endl;
			}
		}
		else
		{
			cout << "    Sorry!! A problem occurred while opening the file." << endl;
		}
		
	}
	else if (update == '2')
	{
		int j, c, d, t, i = 0;
		int check = 1;
		SupplierFile.open("SupplierFile.text");
		if (SupplierFile.is_open())
		{
			while (!SupplierFile.eof())
			{
				SupplierFile >> Supplier_name[i] >> Phone_number[i] >> Supplier_Brand[i];
				i++;
			}
			i--;
			cout << "\n    Please choose the supplier that you want to update By ID :" << endl << endl;
			for(j = 0; j < i ; j++)
			{
				cout << endl << "    ID : " << j << "\t";
				cout << "    Supplier name : " << Supplier_name[j] << "\t";
				cout << "    Phone number : " << Phone_number[j] << "\t";
				cout << "    Brand : " << Supplier_Brand[j] << endl; 
			}
			cout << endl<< "    Enter Supplier ID to update it :";
			cin >> c;
			for (d = 0; d < j; d++)
			{
				if (d == c)
				{
					check = 0;
				}
			}
			if (check == 0)
			{
				system("cls");
				cout << endl << "    The previous record : \n" << endl;
				cout << "    Supplier name : " << Supplier_name[c] << "\t";
				cout << "    Phone number : " << Phone_number[c] << "\t";
				cout << "    Brand : " << Supplier_Brand[c] << endl;
				cout << endl << "*******************************************************************************" << endl;
				cout << endl << "    Please Enter The new record : \n" << endl;
				cout << "    Supplier name : ";
				cin >> Supplier_name[c];
				cout << "    Phone number : ";
				cin >> Phone_number[c];
				cout << "    Brand : ";
				cin >> Supplier_Brand[c];
				cout << endl << "*******************************************************************************" << endl;
				TempSFile.open("Temp.text", ios::app);
				if (TempSFile.is_open())
				{
					for(t = 0 ; t < i ; t++)
					{
						TempSFile << Supplier_name[t] << " " << Phone_number[t] << " " << Supplier_Brand[t] << endl;
					}
					SupplierFile.close();
					TempSFile.close();
					remove("SupplierFile.text");
					rename("Temp.text","SupplierFile.text");
					cout << endl << "\t Record was updated successfully." << endl;
				}
				else
				{
					cout << "    Sorry!! A problem occurred while opening the file." << endl;
				}
			}
			else
			{
				cout << "    Wrong input !! Please be sure that you have choose a correct ID." << endl;
			}	
		}
		else
		{
			cout << "    Sorry!! A problem occurred while opening the file." << endl;
		}
	}
	GoodsFile.close();
	TempFile.close();
	SupplierFile.close();
	TempSFile.close();
	cout << "\t Press ENTER to continue ..." << endl;
	cin.get();
}

void Delete_Goods_Record()
{
	system("cls");
	int d, j, c, i = 0;
	int check = 1;
	fstream GoodsFile;
	fstream TempGoods;
	GoodsFile.open("GoodsFile.text");
	if (GoodsFile.is_open())
	{
		while (!GoodsFile.eof())
		{
			GoodsFile >> Goods_name[i] >> UPC_code[i] >> quantity[i] >> Goods_Brand[i];
			i++;
		}
		i--;
		for (j = 0; j < i; j++)
		{
			cout << endl << "****************************************************" << endl;
			cout << "    ID : " << j << "    Product name : " << Goods_name[j] << "    UPC code : " << UPC_code[j];
			cout << "    Quantity : " << quantity[j] << "    Brand : " << Goods_Brand[j];
			cout << endl << "****************************************************" << endl;
		}
		cout << endl << "Please Enter The ID for the product you want to delete : ";
		cin >> d;
		for (c = 0; c < j; c++)
		{
			if (c == d)
			{
				check = 0;
			}
		}
		if (check == 0)
		{
			TempGoods.open("Temp.text", ios::app);
			if (TempGoods.is_open())
			{
				for (j = 0; j < i; j++)
				{
					if (j != d)
					{
						TempGoods << Goods_name[j] << "  " << UPC_code[j] << "  " << quantity[j] << "  " << Goods_Brand[j] << endl;
					}
				}
				GoodsFile.close();
				TempGoods.close();
				remove("GoodsFile.text");
				rename("Temp.text","GoodsFile.text");
				cout << endl << "    Goods record deleted successfully." << endl;
			}
			else
			{
				cout << "    Sorry!! A problem occurred while opening the file." << endl;
			}
		}
		else
		{
			cout << endl << "    You selected a wrong goods ID ..." << endl;
		}	
	}
	GoodsFile.close();
	TempGoods.close();
	cout << "    Press ENTER to continue ...";
	cin.get();
}

void Delete_Supplier_Record()
{
	system("cls");
	int d, j, c, i = 0;
	int check = 1;
	fstream SupplierFile;
	fstream TempSupplier;
	SupplierFile.open("SupplierFile.text");
	if (SupplierFile.is_open())
	{
		while(!SupplierFile.eof())
		{
			SupplierFile >> Supplier_name[i] >> Phone_number[i] >> Supplier_Brand[i];
			i++;
		}
		i--;
		cout << "\t\tSuppliers List : " << endl;
		cout << "*****************************************************" << endl;
		for (j = 0; j < i; j++)
		{
			cout << "    ID :" << j << "    Supplier name : " << Supplier_name[j] << "    Phone number : " << Phone_number[j];
			cout << "    Brand : " << Supplier_Brand[j] << endl;
			cout << "*****************************************************" << endl;
		}
		cout << "Please choose the ID of Supplier that you want to delete : ";
		cin >> d;
		for (c = 0; c < j; c++)
		{
			if (c == d)
			{
				check = 0;
			}
		}
		if (check == 0)
		{
			TempSupplier.open("TempSupplier.text", ios::app);
			if (TempSupplier.is_open())
			{
				for (i = 0; i < j; i++)
				{
					if (i != d)
					{
						TempSupplier << Supplier_name[i] << "  " << Phone_number[i] << "  " << Supplier_Brand[i] << endl;
					}
				}
				SupplierFile.close();
				TempSupplier.close();
				remove("SupplierFile.text");
				rename("TempSupplier.text","SupplierFile.text");
				cout << endl << "    Supplier record deleted successfully." << endl;
			}
			else
			{
				cout << "    Sorry!! A problem occurred while opening the file." << endl;
			}
		}
		else
		{
			cout << endl << "    You selected a wrong supplier ID ..." << endl;
		}
	}
	else
	{
		cout << "    Sorry!! A problem occurred while opening the file." << endl;
	}
	SupplierFile.close();
	TempSupplier.close();
	cout << "    Press ENTER to continue ...";
	cin.get();
}

void Introduction()
{
	cout << "\n\t" << "----------------\n\t|  SUPER       |\n \t|  MARKET      | \n \t|  MANAGEMENT  |\n \t|  SYSTEM      | \n\t----------------" << endl;
	cout << "\t" << "Here you can track and manage for your market goods and suppliers." << endl;
	cout << "\t" << "Please Press ENTER to start." << endl << "\t";
	cin.get();
}


