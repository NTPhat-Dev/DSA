#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	int age;
	double gpa;
};

struct Node
{
	Student student;
	Node* nextNode;
};

typedef struct Node* listHS;

listHS inputStudent()
{
	int soHocSinh;
	cout << "Nhap so sinh vien: ";
	cin >> soHocSinh;
	
	if (soHocSinh <= 0) {
		cout << "So hoc sinh khong hop le" << endl;
		return nullptr;
	}
	
	listHS head = nullptr;
	listHS tail = nullptr;
	
	for (int i = 0 ; i < soHocSinh ; i++)
	{
		listHS newNode = new Node;
		
		cout << "Nhap ten sinh vien thu " << i+1 <<": ";
		cin.ignore();
		getline(cin, newNode->student.name);
		
		cout << "Nhap tuoi sinh vien: ";
		cin >> newNode->student.age;
		
		cout<< "Nhap diem GPA: ";
		cin >> newNode->student.gpa;
		newNode->nextNode = nullptr;
		
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		} else {
			tail->nextNode = newNode;
			tail = newNode;
		}
	}
	return head;
}

void printList(listHS head)
{
	listHS element = head;
	while (element != nullptr)
	{
		cout << "Name: " << element->student.name <<endl;
		cout << "Age: " << element->student.age <<endl;
		cout << "GPA: " << element->student.gpa <<endl;
		cout << "-----------------------------------"<<endl;
		element = element->nextNode;	
	} 
}

int countStudent(listHS head)
{
	int count = 0;
	listHS tmp = head;
	
	while (tmp != nullptr) {
		count++;
		tmp = tmp->nextNode;
	}
	return count;
}

listHS createNewList(listHS head)
{
	listHS gpa8Head = nullptr;
	listHS gpa8Tail = nullptr;
	
	listHS element = head;
	while(element != nullptr) 
	{
		if (element->student.gpa >= 8) 
		{
			listHS newNode = new Node;
			newNode->student = element->student;
			newNode->nextNode = nullptr;
			
			if (gpa8Head == nullptr) 
			{
				gpa8Head = newNode;
				gpa8Tail = newNode;
			} else {
				gpa8Tail->nextNode = newNode;
				gpa8Tail = newNode;
			}
		}
		element = element -> nextNode;
	}
	return gpa8Head;
}

void searchStudent(listHS head, const string& name)
{
	listHS element = head;
	bool check = false;
	
	while (element != nullptr)
	{
		if (element->student.name == name)
		{
			cout << "Sinh vien can tim" << endl;
			cout << "Name :" << element->student.name << endl;
			cout << "Age: " << element->student.age << endl;
			cout << "GPA: " << element->student.gpa << endl;
			cout << "-----------------------------------" <<endl;
			check = true;
			break;
		}
		element = element->nextNode;
	}
	
	if (!check)
	{
		cout << "Khong tim thay" <<endl;
	}
}

void deleteStudent(listHS& head, const string& name) 
{

}

void giaiPhong(listHS head)
{
	while (head != nullptr)
	{
		listHS tmp = head;
		head = head->nextNode;
		delete tmp;
	}
}

int main()
{
	int value = 0;
	string name1;
	listHS input = nullptr;
	listHS newListGpa8 = nullptr;
	
	cout << "--------------------Thuc Hanh Danh Sach Lien Ket Don--------------------" << endl;
	
	do
	{
		cout << "1. Nhap danh sach hoc sinh" <<endl;
		cout << "2. In danh sach hoc sinh" <<endl;
		cout << "3. Dem so luong sinh vien" << endl;
		cout << "4. Tao danh sach sinh vien co gpa >= 8 tu danh sach cho truoc" <<endl;
		cout << "5. Tim 1 sinh vien theo ten" << endl;
		cout << "6. Xoa 1 sinh vien theo ten" << endl;
		cout << "7. Them 1 sinh vien vao vi tri k" <<endl;
		cout << "8. Xoa 1 sinh vien tai vi tri k" <<endl;
		cout << "9. Sap xep danh sach theo thu tu giam diem trung binh" <<endl;
		cout << "10. Them 1 sinh vien vao danh sach sap theo thu tu giam diem trung binh" <<endl;
		cout << "11. Dong chuong trinh" <<endl;
		cout << "Nhap lua chon: ";
		cin >> value;
		
		switch(value)
		{
			case 1:
				input = inputStudent();
				break;
			case 2:
				printList(input);
				break;
			case 3:
				cout << "So luong sinh vien: " << countStudent(input) <<endl;
				break;
			case 4:
				newListGpa8 = createNewList(input);
				cout << "Danh sach sinh vien co GPA >= 8" <<endl;
				printList(newListGpa8);
				break;
			case 5:
				cout << "Nhap ten can tim: ";	
				cin.ignore();
				getline(cin, name1);
				searchStudent(input, name1);
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			default:
				cout << "Lua chon khong hop le. Nhap lai!!" <<endl;
				cout << "--------------------------------------------------"<<endl;
				break;
		}
	} while (value != 11);
	
	
	giaiPhong(input);
	giaiPhong(newListGpa8);
	return 0;
}