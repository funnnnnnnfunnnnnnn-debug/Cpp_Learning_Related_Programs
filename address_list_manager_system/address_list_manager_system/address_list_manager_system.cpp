#include<iostream>
using namespace std;
#include<string>;
#define MAX 1000

void showMenu()
{
	cout << "****************************"<<endl;
	cout << "*******1、添加联系人********" << endl;
	cout << "*******2、显示联系人********" << endl;
	cout << "*******3、删除联系人********" << endl;
	cout << "*******4、查找联系人********" << endl;
	cout << "*******5、修改联系人********" << endl;
	cout << "*******6、清空联系人********" << endl;
	cout << "*******0、退出通讯录********" << endl;
	cout << "****************************" << endl;
	cout << "请选择你的操作:"<<endl;
}
struct Person
{
	string name;
	string gender;
	int age;
	string number;
	string address;
};
struct List
{
	Person personarray[MAX];
	int size;
};
void Exit()
{
	cout << "欢迎下次使用" << endl;

}
void Add( List *abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法添加";
		return;
	}
	else
	{
		string name;
		string gender;
		int age;
		string number;
		string address;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;
		cout << "请输入性别：" << endl;
		cin >> gender;
		abs->personarray[abs->size].gender =gender;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;
		cout << "请输入电话：" << endl;
		cin >> number;
		abs->personarray[abs->size].number = number;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->personarray[abs->size].address= address;

		abs->size++;
		cout << "添加成功！";

		system("pause");
		system("cls");
	}
	
}
void Show(List* abs)
{
	if (abs->size == 0)
	{
		cout << "目前通讯录为空，请添加。"<<endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout<< "姓名: " << abs->personarray[i].name << "  " << "性别: " << abs->personarray[i].gender << "  " << "年龄: " << abs->personarray[i].age << "  " << "电话: " << abs->personarray[i].number << "  " << "住址: " << abs->personarray[i].address << "  " << endl;
		}
	}
	system("pause");
	system("cls");
}
int isexist(List* abs, string name)
{
	for (int i = 0; i < (abs->size); i++)
	{
		if (abs->personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
void Delete(List* abs)
{
	cout << "请输入删除联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (isexist(abs, name)== -1)
	{
		cout << "查无此人，请重新输入" << endl;
	}
	else
	{
		cout << "找到了编号为" << isexist(abs, name) + 1 << endl;
		cout << "是否要删除,确认按1，取消按0"<<endl;
		int input = 0;
		cin >> input;
		if (input == 1)
		{
			for (int i = ret; i < abs->size; i++)
			{
				abs->personarray[i] = abs->personarray[i + 1];
			}
			abs->size--;
			cout << "删除成功" << endl;
		}

	}
	system("pause");
	system("cls");
}
void Find(List *abs)

{
	cout << "请输入你想查找的联系人"<<endl;
	string name;
	cin >> name; 
	if (isexist(abs, name) == -1)
	{
		cout << "查无此人，请重新输入" << endl;
	}
	else
	{
		cout << "找到了编号为" << isexist(abs, name) + 1 << endl;
	    cout << "姓名: " << abs->personarray[isexist(abs, name)].name << "  " << "性别: " << abs->personarray[isexist(abs, name)].gender << "  " << "年龄: " << abs->personarray[isexist(abs, name)].age << "  " << "电话: " << abs->personarray[isexist(abs, name)].number << "  " << "住址: " << abs->personarray[isexist(abs, name)].address << "  " << endl;
	}
	system("pause");
	system("cls");
}
void Change(List *abs)
{
	cout << "请输入你想修改的联系人" << endl;
	string name;
	cin >> name;
	if (isexist(abs, name) == -1)
	{
		cout << "查无此人，请重新输入" << endl;
	}
	else
	{
		cout << "找到了编号为" << isexist(abs, name) + 1 << endl;
		cout << "姓名: " << abs->personarray[isexist(abs, name)].name << "  " << "性别: " << abs->personarray[isexist(abs, name)].gender << "  " << "年龄: " << abs->personarray[isexist(abs, name)].age << "  " << "电话: " << abs->personarray[isexist(abs, name)].number << "  " << "住址: " << abs->personarray[isexist(abs, name)].address << "  " << endl;
		string name_new;
		string number_new;
		string gender_new;
		int age_new;
		string add_new;
		int input;
		cout << "请输入你想修改的内容：1、姓名 2、性别 3、年龄 4、电话 5、住址" << endl;
		cin >> input;
		cout << "请输入" << endl;
		switch (input)
		{
		case 1:
			cin >> name_new;
			abs->personarray[isexist(abs, name)].name = name_new;
			break;
		case 2:
			cin >> gender_new;
			abs->personarray[isexist(abs, name)].gender = gender_new;
			break;
		case 3:
			cin >> age_new;
			abs->personarray[isexist(abs, name)].age = age_new;
			break;
		case 4:
			cin >> number_new;
			abs->personarray[isexist(abs, name)].number = number_new;
			break;
		case 5:
			cin >> add_new;
			abs->personarray[isexist(abs,name)].address= name_new;
			break;
		}
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}

void Empty(List *abs)
{
	cout << "此操作将会清空通讯录，请谨慎执行，确认请输入1" << endl;
	int input;
	cin >> input;
	if (input == 1)
	{
		abs->size = 0;
		cout << "已清空" << endl;
	}
	system("pause");
	system("cls");

	}
int main()
{List abs;

		abs.size = 0;
	while (1)
	{
		showMenu();
		
		int input;
		cin >> input;

		switch (input)
		{
		case 1:
		{
			Add(&abs);
			break;
		}
		case 2:
		{
			Show( & abs);
			break;
		}
		case 3:
		{
			Delete(&abs);
			break;
		}
		case 4:
		{
			Find(&abs);
			break;
		}
		case 5:
		{
			Change(&abs);
			break;
		}

		case 6:
		{
			Empty(&abs);
			break;
		}
		case 0:
		{
			Exit();
			return 0;
			break;
		}
		default:
		{
			cout << "您的输入不合法，请重新输入。" << endl;
			break;
		}
		}
	}
	
	system("pause");
	return 0;
}
