#include<iostream>
#include<string>

using namespace std;



struct book{       //A structure to store details of the book
	int uniqueID;
	string title;
	string author;
	bool available;
	struct book *link;
}*start = NULL;

struct studentDetail{      //A structure to store details of the student
	int uniqueBookID;
	string studentID;
	string name;
	struct studentDetail *link;
	
}*studentDetailstart=NULL;

struct issuedBook{       //A structure to store details of the issued books
	int uniqueID;
	string title;
	string author;
	struct issuedBook *link;
}*issuedBookstart=NULL;

void displayIssueBookdetails()
{
	struct issuedBook *ib = issuedBookstart;
	while(ib!=NULL)
	{
		cout<<endl;
		cout<<"Unique ID: "<<ib->uniqueID<<" \n";
		cout<<"Title :"<<ib->title<<"\n ";
		cout<<"Author:"<<ib->author<<" \n";
		ib = ib->link;

	}
}

void displayIssuedStudentDetials()
{
	struct studentDetail *sd = studentDetailstart;
	while (sd != NULL)
	{
		cout<<endl;
		cout<<"UniqueID: "<<sd->uniqueBookID<<"\n";
		cout<<"Student name: "<<sd->name<<"\n";
		cout<<"studentID: "<<sd->studentID<<"\n";
		sd = sd->link;
	}
}

void someBooks()
{
	struct book *a = new book;
	a->uniqueID = 1;
	a->title = "dune";
	a->author = "Frank Herbert";
	a->available = true;
	a->link=start;
	start =a;
	
	struct book *ab = new book;
	ab->uniqueID = 2;
	ab->title = "beloved";
	ab->author = "Toni Morrison";
	ab->available = true;
	ab->link=NULL;
	a->link=ab;
	
	struct book *abc = new book;
	abc->uniqueID = 3;
	abc->title = "Animal Farm";
	abc->author = "George Orwell";
	abc->available = true;
	abc->link=NULL;
	ab->link = abc;
	
	struct book *abcd = new book;
	abcd->uniqueID = 8;
	abcd->title = "Harry Potter";
	abcd->author = "J.K ROWLING";
	abcd->available = true;
	abcd->link=NULL;
	abc->link = abcd;
		
}


//To add new book
void addNewBook() {
    struct book* n = new book;
    struct book* p = start;
    struct book* save = NULL;

    cout << "Please enter the details of the book" << endl;
    cout << "Enter the uniqueID of the book: ";
    cin >> n->uniqueID;
    if(n->uniqueID >0)
    {
    	cin.ignore(); 

    cout << "Enter the title of the book: ";
    getline(cin, n->title);

    cout << "Enter the name of the author of the book: ";
    getline(cin, n->author);

    n->available = true;
    n->link = NULL;

    if (start == NULL) {
        start = n;
        cout << "\nBook added successfully" << endl;
        return;
    }

    if (n->uniqueID < start->uniqueID) {
        n->link = start;
        start = n;
        cout << "\nBook added successfully" << endl;
        return;
    }

    while (p != NULL) {
        if (n->uniqueID == p->uniqueID) {
        	cout<<endl<<"Operation is failed";
            cout << "\nBook with the same uniqueID already exists." << endl;
            cout<<"So kindly check the uniqueID again";
            return;
        }

        if (p->link != NULL && n->uniqueID < p->link->uniqueID) {
        	save = p;
        	p=p->link;
        	
            break;
        }

        save = p;
        p = p->link;
    }

    n->link = p;
    save->link = n;
    cout << "\nBook added successfully" << endl;
	}
	else
	{
		cout<<"Invalid input for uniqueID";
	}
    
}


//To search the book using ID
void searchBookByID()
{
	int sebID;
	struct book *seID = start;
	cout<<"\nEnter the uniqueID of the book:";
	cin>>sebID;
	while(seID != NULL)
	{
		if(seID->uniqueID == sebID)
		{
			cout<<endl;
			cout<<"Book found";
			cout<<"\nBookID:"<<seID->uniqueID<<endl;
			cout<<"Title of the book:"<<seID->title<<endl;
			cout<<"Author of the book:"<<seID->author<<endl;
			if(seID->available)
			{
				cout<<"Availabilty:"<<"Yes"<<endl;
			}
			else
			{
				cout<<"Availability:"<<"NO"<<endl;
			}
			break;
		
			
		}
		seID=seID->link;
	}
	
	if(seID == NULL)
	{
		cout<<"Book not found";
	}
}


//To search book using title of the book
void searchBookByTitle()
{
	string sebtitle;
	struct book *setitle = start;
	cout<<"Enter the title of the book:";
	cin.ignore();
	getline(cin,sebtitle);
	while(setitle != NULL)
	{
		if(setitle->title == sebtitle)
		{
			cout<<endl;
			cout<<"Book found";
			cout<<"\nBookID:"<<setitle->uniqueID<<endl;
			cout<<"Title of the book:"<<setitle->title<<endl;
			cout<<"Author of the book:"<<setitle->author<<endl;
			if(setitle->available)
			{
				cout<<"Availabilty:"<<"Yes"<<endl;
			}
			else
			{
				cout<<"Availability:"<<"NO"<<endl;
			}
			break;	
		}
		setitle=setitle->link;
	}
	
	if(setitle == NULL)
	{
		cout<<endl;
		cout<<"Book not found";
	}
}


//To issue a book
void issueBook()
{
	int bookID;
	struct book *b = start;  

	cout << "\nEnter the unique ID of the book: ";
	cin >> bookID;
	

	while (b != NULL)
	{
		if (b->uniqueID == bookID)
		{
			if (b->available)
			{
				cout << "Book found and available";
				cout<<"\nBook uniqueID :"<<b->uniqueID;
				cout<<"\nBook name:"<<b->title;
				cout<<"\nAuthor name:"<<b->author;
				b->available = false;
				
				//storing details of issued book
				struct issuedBook *i = new issuedBook;
				i->author = b->author;
				i->title = b->title;
				i->uniqueID = b->uniqueID;
				i->link=issuedBookstart;
				issuedBookstart = i;
				
				//storing student details
				struct studentDetail *d = new studentDetail;
				d->uniqueBookID = b->uniqueID;
				cout<<"\nEnter student name:";
				cin.ignore();
				getline(cin,d->name);
				cout<<"Enter student id:";
				cin.ignore();
				getline(cin,d->studentID);
				d->link = studentDetailstart;
				studentDetailstart = d;
				
				cout<<"book issued successfully to "<<d->name;
				break;
				
			}
			else
			{
				cout << "\nBook is not available";
			}
		}

		b = b->link;  
	}

	if (b == NULL)
	{
		cout << "\nBook not found";
	}
}


//To return a book 
void returnBook()
{
	int returnedBookID;
	cout<<"\nEnter the bookID:";
	cin>>returnedBookID;
	struct book *bo = start;	
	while(bo!=NULL)
	{
		if(bo->uniqueID == returnedBookID)
		{
			if(!bo->available)
			{
				bo->available = true;
				cout<<endl;
				cout<<"Book returned succesfully";
				break;
			}
		}
		bo=bo->link;
	}
	
	if(bo==NULL)
	{
		cout<<endl<<"book not found";
	}
}



//To list all books
void listAllBooks()
{
	int count=0;
	int availablecount=0;
	cout<<"\nListing All books:";
	struct book *ptr=start;
	struct book *temp;
	
	
	
	while(ptr!=NULL)
	{
		cout<<"\nBookID:"<<ptr->uniqueID<<endl;
		cout<<"Title of the book:"<<ptr->title<<endl;
		cout<<"Author of the book:"<<ptr->author<<endl;
		count++;
		if(ptr->available)
		{
			cout<<"Availabilty:"<<"Yes"<<endl;
			availablecount++;
		}
		else
		{
			cout<<"Availability:"<<"NO"<<endl;
		}
		ptr=ptr->link;
	}
	cout<<"\nTotal books in libray:"<<count;
	cout<<"\nAvailable books in library:"<<availablecount;
	cout<<"\nissued books from library:"<<count-availablecount;
		
}


//To delete a book
void deleteBook()
{
	int deleteBookID;
	struct book *del = start;
	struct book *save = NULL;
	cout<<"Enter uniqueID of the book:";
	cin>>deleteBookID;
	while(del!=NULL && del->uniqueID != deleteBookID)
	{
		save = del;
		del = del->link;
	}
	
	if(del==NULL)
	{
		cout<<endl<<"book not found";
	}
	else
	{
		if(del == start)
		{
			cout<<"book found";
			cout<<"\nbook uniqueID:"<<del->uniqueID;
			cout<<"\nbook title:"<<del->title;
			cout<<"\nbook author:"<<del->author;
			
			start = start->link;
			cout<<"\ndeleted successfully";
		}
		else
		{
			cout<<"\nbook uniqueID:"<<del->uniqueID;
			cout<<"\nbook title:"<<del->title;
			cout<<"\nbook author:"<<del->author;
			
			save->link = del->link;
			cout<<"\ndeleted successfully";
		}
	}
	
}


int main()
{
	someBooks();
	cout<<"Welcome to LIBRARY MANAGEMENT SYSTEM";
	
	int c=0;
	while((c>=0) && (c<20))
	{
	cout<<endl;
	cout<<endl;
	
	cout<<"-----------------------------------------";
	cout<<endl;
	cout<<"Please choose an option from the menu";
	cout<<"\nMenu:";
	cout<<"\n choose 1 to add a book";
	cout<<"\n choose 2 to search for a book by ID";
	cout<<"\n choose 3 to search for a book by title";
	cout<<"\n choose 4 to issue a book";
	cout<<"\n choose 5 to return a book";
	cout<<"\n choose 6 to list all books";
	cout<<"\n choose 7 to delete a book";
	cout<<"\n choose 8 to display issued book details";
	cout<<"\n choose 9 to display student details";
	cout<<"\n choose 10 to exit the program";
	
	cout<<"\nchoose option:";
	cin>>c;
	
	switch(c)
	{
		case 1 : addNewBook();
		break;
		
		case 2: searchBookByID();
		break;
		
		case 3: searchBookByTitle();
		break;
		
		case 4: issueBook();
		break;
		
		case 5: returnBook();
		break;

		case 6 : listAllBooks();
		break;
		
		case 7: deleteBook();
		break;

		case 8: displayIssueBookdetails();
		break;

		case 9: displayIssuedStudentDetials();
		break;
		
		default:cout<<"Please enter valid choice";
		break; 

	}
}
	
}
