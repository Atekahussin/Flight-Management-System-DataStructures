#include <iostream>
#include <string>

using namespace std ;

// All structures must be written here

struct Passenger { 

    string name, Address;
	string PassengerTicketDegree;
	int ID, PhoneNumber,TicketNumber, PassportNumber; 
	
	Passenger *link ;
	
}; 

// All pointers of structure must be wrriteen here

Passenger *head = NULL, *tail = NULL, *temp = NULL, *cur = NULL ;

// All function prototypes must be written here

void PassengerService(int) ;
void ManagerService(int) ;
void DisplayPassengerDetails() ;
void PurchaseATicket() ;
void SearchPassengerByNumber(int passengerNumber);
void SearchPassengerByName(const string& name);
void UpgradeOrDegradeTicket(Passenger* passenger);
void displayAllPassengers() ;
bool ID_Validation(int) ;

// The main function has All types of menus 

int main()
{
	int choice ;
	int PassChoice ;
	int ManChoice ;
	bool flag ;
	
	do
	{
		flag = false ;
		
		cout << "----------------------------" << endl ;
		cout << "---         MENU         ---" << endl ;
		cout << "----------------------------" << endl ;
		
		cout << "Welcome to our airlines! are you a flight passenger or a flight manager?" << endl ;
		cout << endl ;
		cout << "1) Flight Passenger. \n2) Flight Manager. \n3) Exit." << endl ;
		cout << endl ;
		cout << "Enter your choice: " ;
		cin >> choice ;
		
		switch(choice)
		{
			case 1 :
				{
					do
					{
						
						cout << "----------------------------" << endl ;
	                	cout << "---  PASSENGER SERVICES  ---" << endl ;
	                	cout << "----------------------------" << endl ;
	                	cout << endl ;
	                	cout << "1) Purchase a ticket. \n2) Upgrade or Degrade a ticket! \n3) Print Passenger's informatiom. \n4) Go back to main menu " << endl ;
	                	cout << endl ; 
						cout << "Enter your choice: " ;
	                	cin >> PassChoice ;
	    
						
						switch(PassChoice)
						{
							case 1 :
							case 2 :
							case 3 :
								{
									PassengerService(PassChoice) ;
									flag = true ;
									break ;
								}
								
							case 4 :
								{
									flag = true ;
									break ;
								}
								
							default :
								{
									cout << endl ;
						        	cout << "Wrong entry! Try again!" << endl ;
								}
						}
						
						
						
					}while(flag = false);
					
					break ;
				}
				
			case 2 :
			{
				do
				{
					
						cout << "----------------------------" << endl ;
	                	cout << "---   MANAGER SERVICES   ---" << endl ;
	                	cout << "----------------------------" << endl ;
	                	cout << endl ;
	                	cout << "1) Search Passenger with ID. \n2) Search passenger with name. \n3) Display all passengers. \n4) Go back to main menu. " << endl ;
	                	cout << endl ; 
						cout << "Enter your choice: " ;
	                	cin >> ManChoice ;
	                	
	                	if(ManChoice == 1 || ManChoice == 2 || ManChoice == 3)
	                	{
	                		ManagerService(ManChoice) ;
	                		flag = true ;
						}
						
						else if(ManChoice == 4)
						{
							flag = true ;
							cout << endl ;
						}
						
						else
						{
							cout << endl ;
							cout << "Wrong entry! Try again!" << endl ;
						}
						
				}while(flag = false);
				
				break ;
				
			} 
			
			case 3: 
			{
				cout << endl ;
				cout << "Exiting the menu! Thank you for choosing our airlines!" << endl ;
				
				break ; 
			}
			
			default :
				{
					cout << endl ;
					cout << "Invalid entry! Try again!" << endl ;
				}
		}
			
	}while(choice != 3);
	
	return 0 ;
}

void PassengerService(int option) 
{
	switch(option)
	{
		case 1 :
			{
				// Purchase a ticket function must be written here 
				PurchaseATicket();
				break ;
			}
			
		case 2 :
			{
				 int passengerID;
                cout << "Enter passenger ID for ticket upgrade or degrade: ";
                cin >> passengerID;

                Passenger* currentPassenger = head;

                // Search for the passenger by ID
                while (currentPassenger != NULL && currentPassenger->ID != passengerID)
				{
                    currentPassenger = currentPassenger->link;
                }

                if (currentPassenger == NULL) 
				{
                    cout << "Passenger not found!" << endl;
                } 
				
				else
			    {
                    // Upgrade or Degrade a ticket function must be written here
                    UpgradeOrDegradeTicket(currentPassenger);
                }
				
				break ;
			}
			
		case 3 :
			{
				// Display passenger info function must be written here
				 DisplayPassengerDetails();
				 
				break ;
			}
				
	}
}

void ManagerService(int option) 
{
	switch(option)
	{
		case 1 :
			{
				// Search for passenger by id function must be written here
				int passengerNumber;
                cout << "Enter the Passenger ID to search: ";
                cin >> passengerNumber;
                SearchPassengerByNumber(passengerNumber);
				
				break ;
			}
			
		case 2 :
			{
				// Search for passenger by name function must be written here
                string searchName;
                cout << "Enter passenger name to search: ";
                cin.ignore(); // Ignore any previous newline character in the buffer
                getline(cin, searchName);
                SearchPassengerByName(searchName);	
                
                break;
			}
			
		case 3 :
			{
				displayAllPassengers() ;
				break ;
			}
			
				
	}
}

//Write all the functions down here 

void PurchaseATicket()
{
	temp = new Passenger ;
	
	int choice, option ;
	int id ;
	bool match ;
	
	cout << endl ;
	
	cout<<"***************** Passenger Details *****************" << endl;

    do 
    {
	  
	cout<<"Please Enter Your ID: "<< endl;
	cin >> id ;
	match = ID_Validation(id) ;
	
	if(match == true)
	{
		cout << "The inserted ID is already existed!" << endl ;
		cout << "Would you like to try another ID or cancel your purchase?" << endl ;
		cout << "1) Try another ID. \n2) Cancel." << endl ;
		cout << "Your option: " ;
		cin >> option ;
		
		cout << endl ;
		
		if(option == 1)
		{
			match = true ;
		}
		
		else if(option == 2)
		{
			cout << "Canceling purchase!" << endl ;
			
			delete temp ;
			
			return ;
		}
		
		else
		{
			cout << "INVALID ENTRY! TRY AGAIN!" << endl ;
			match = true ;
		}
	}
	
	else
	{
		cout << "ID is valid!" << endl ;
		temp->ID = id ;
	}

    }while(match == true) ;
    
	cout<<"Please Enter Your Name: " ;
	cin.ignore() ;
	getline(cin, temp->name) ;
	
	cout<<"Please Enter Your Passport Number: " ;
	cin>>temp->PassportNumber;
	
    cout<<"Please Enter Your Phone Number: " ;
	cin>>temp->PhoneNumber;
	
    cout<<"Please Enter Your Adderss: ";
    cin>>temp->Address;
    
    cout<<"Please Enter Your Ticket Number: " ;
    cin>>temp->TicketNumber;
             	
    cout<<"Choose Your Ticket degree: " << endl ;
 	            
	cout << "----------------------------" << endl ;
	cout << "---   PASSENGER Ticket   ---" << endl ;
	cout << "----------------------------" << endl ;
	            
    cout << "1. High Class     \t2500 SAR." << endl ;
    cout << "2. business Class \t1750 SAR. " << endl ;
    cout << "3. Economy Class \t800 SAR." << endl ;
    
	cout << endl ;
              	
    cout << "Enter your choice: " ;
    cin >> choice ;
             	
    switch(choice)   
	{
		case 1 :
	                          
	    {
	        cout << "-------------------------------------" << endl ;
	        cout << "Passenger Ticket Degree is High Class" << endl ;
	        cout << "-------------------------------------" << endl ;
	                                
	        temp->PassengerTicketDegree = "High Class" ;
	                                
	        break ;
	    }
		            
	                
	    case 2 :
	                         
	    {
	        cout << "-----------------------------------------" << endl ;
	        cout << "Passenger Ticket Degree is Business Class" << endl ;
	        cout << "-----------------------------------------" << endl ;
	                                
	        temp->PassengerTicketDegree = "Business Class" ;
	                                
	        break ;
	    }
	                
	                
	    case 3 :
	                           
	    {
	        cout << "----------------------------------------" << endl ;
	        cout << "Passenger Ticket Degree is Economy Class" << endl ;
	        cout << "----------------------------------------" << endl ;
	                                
	        temp->PassengerTicketDegree = "Economy Class" ;
	                                
	        break ;
	    }
		            
		default :
		{
			cout << endl ;
			cout << "Invalid entry! Try again!" << endl ;
		}
				
    }   	
	
	temp->link = NULL ;
	
	if (head == NULL)
	{
		head = tail = temp ;
	}
	
	else
	{
		tail->link = temp ;
		tail = temp ;
	}
	
	cout << endl ;
	cout << "Ticket is purchased successfully!" << endl ;
	cout << endl ;
	
}

void DisplayPassengerDetails() 
{
	
	cur = head ;
	
	int id ;
	cout << "Enter your ID number: " ;
	cin >> id ;
	
	while(cur != NULL)
	{
		if(id == cur->ID)
		{
			cout << endl ;
			
			cout << "------ DETAILS FOR PASSENGER [ " << cur->name << " ] ------" << endl;
			
           cout << "----------------------" << endl ;
        	
            cout << "Name " << cur->name << endl ;
	
	        cout << "ID: " << cur->ID << endl ;
	
         	cout << "Passport Number: " << cur->PassportNumber << endl ;
	
            cout << "Phone Number: " << cur->PhoneNumber << endl ;
	
            cout << "Adderss: " << cur->Address << endl ; 
    
            cout << "Ticket Number: " << cur->TicketNumber << endl ;
             	
            cout << "Ticket degree: " << cur->PassengerTicketDegree << endl ;
           
            cout << "----------------------" << endl ;

			return ;
		}
		
		cur = cur->link ;
	}
	
	cout << "There is no passenger with the ID [ " << id << " ]" << endl ;
}

void SearchPassengerByNumber(int passengerNumber) 
{
    Passenger *current = head;

    while (current != NULL) {
        if (current->ID == passengerNumber) {
            // Passenger found, display details
            cout << "Passenger found! Details:" << endl;
            cout << "  Passenger Name: " << current->name << endl;
            cout << "  Passenger ID: " << current->ID << endl;
            cout << "  Passenger Passport Number: " << current->PassportNumber << endl;
            cout << "  Passenger Phone Number: " << current->PhoneNumber << endl;
            cout << "  Passenger Address: " << current->Address << endl;
            cout << "  Passenger Ticket Number: " << current->TicketNumber << endl;
            cout << "  Passenger Ticket Degree: " << current->PassengerTicketDegree << endl;

            return ; // Exit the function after finding the passenger
        }

        current = current->link ;
    }

    // Passenger not found
    cout << "Passenger with ID " << passengerNumber << " not found." << endl;
}

void SearchPassengerByName(const string& name)
{
	
    Passenger* current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->name == name)
        {
            found = true;
            // Display passenger details or perform other actions
            cout << "Passenger found!" << endl;
            cout << "  Passenger Name: " << current->name << endl;
            cout << "  Passenger ID: " << current->ID << endl;
            cout << "  Passenger Passport Number: " << current->PassportNumber << endl;
            cout << "  Passenger Phone Number: " << current->PhoneNumber << endl;
            cout << "  Passenger Address: " << current->Address << endl;
            cout << "  Passenger Ticket Number: " << current->TicketNumber << endl;
            cout << "  Passenger Ticket Degree: " << current->PassengerTicketDegree << endl;
            
            break; // Break out of the loop since the passenger is found
        }

        current = current->link;
    }

    if (!found)
    {
        cout << "Passenger with name '" << name << "' not found." << endl;
    }
}

void UpgradeOrDegradeTicket(Passenger* passenger) 
{
    int choice;
    
    cout << "Current Ticket Degree: " << passenger->PassengerTicketDegree << endl;
    cout << "Choose New Ticket Degree: " << endl;
    cout << "1. High Class" << endl;
    cout << "2. Business Class" << endl;
    cout << "3. Economy Class" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
	 {
        case 1:
            passenger->PassengerTicketDegree = "High Class";
            break;
            
        case 2:
            passenger->PassengerTicketDegree = "Business Class";
            break;
            
        case 3:
            passenger->PassengerTicketDegree = "Economy Class";
            break;
            
        default:
            cout << "Invalid choice! Ticket remains unchanged." << endl;
    }
    
    cout << "Ticket successfully upgraded or degraded!" << endl;
}

void displayAllPassengers()
{
    cur = head ;
    int count = 1 ;

    if(head == NULL)
    {
        cout << "There are no passengers !!" << endl ;
    }
    
    else
    {
        cout << "***************** All Passengers Details *****************" << endl;
        
        while(cur != NULL)
        {
         cout<<"***************** Passenger [ "<< count << " ] Details *****************" << endl ;
         
        	cout << "----------------------" << endl ;
        	
            cout << "Name " << cur->name << endl ;
	
	        cout << "ID: " << cur->ID << endl ;
	
         	cout << "Passport Number: " << cur->PassportNumber << endl ;
	
            cout << "Phone Number: " << cur->PhoneNumber << endl ;
	
            cout << "Adderss: " << cur->Address << endl ; 
    
            cout << "Ticket Number: " << cur->TicketNumber << endl ;
             	
            cout << "Ticket degree: " << cur->PassengerTicketDegree << endl ;
           
            cout << "----------------------" << endl ;
            
            count++ ;
            
            cur = cur->link ;
        }
        
        cout << endl ;
    }
}

bool ID_Validation(int id)
{
	cur = head ;
	
	while(cur != NULL)
	{
		if(id == cur->ID)
		{
			return true ;
		}
		
		cur = cur->link ;
	}
	
	return false ;
	
}
