#include<iostream>
using namespace std;
const int m=50;
class ITEM{
	int itemCode[m];
	int itemPrice[m];
	int cnt;
	public:
		void CNT(void){cnt=0;}
		void getitem();
		void displaysum();
		void deleteitem();
		void displayitems();
};

void ITEM::getitem()
{   
    if (cnt >= m) {
        cout << "Inventory is full! Cannot add more items." << endl;
        return;
    }
	cout<<"enter the item code: "<<endl;
	cin>>itemCode[cnt];
	cout<<"enter the item price: "<<endl;
	cin>>itemPrice[cnt];
	cnt++;  
}
void ITEM::displaysum()
{   
	int ans=0;
	for(int i=0;i<cnt;i++)
		ans=ans+itemPrice[i];
	cout<<"total price: "<<ans<<endl;
}
void ITEM::deleteitem()
{
	int a;
	cout<<"enter item_code for the item you want to delete : ";
	cin>>a;
		 for (int i = 0; i < cnt; i++) {
        if (a == itemCode[i]) {
            // Shift items to the left to remove the item
            for (int j = i; j < cnt - 1; j++) {
                itemCode[j] = itemCode[j + 1];
                itemPrice[j] = itemPrice[j + 1];
            }
            cnt--; // Decrease the count of items
            cout << "Item with code " << a << " deleted." << endl;
            return;
        }
	}
}

void ITEM::displayitems()
{
	for(int i=0;i<cnt;i++)
	{
		cout<<itemCode[i]<<"\n";
		cout<<itemPrice[i]<<"\n";
    }
}
int main()
{
	ITEM i;
	i.CNT();
	int ch;
	cout<<"-----Shopping Mall Billing Counter-----"<<endl;
	do
	{
		cout<<"1.add item\n2.display total\n3.delete item\n4.display items\n5.exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:i.getitem();
				    break;
		    case 2:i.displaysum();
		    		break;
		    case 3:i.deleteitem();
		    		break;
		    case 4:i.displayitems();
		    		break;
		    case 5:exit(0);
		}
	}while(1);
	return 0;
}