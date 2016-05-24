#include<iostream>
#include<string>
using namespace std;

class People //基类人类

{

public:
People(string name,char sex,int age);
//基类的构造函数1
string GetPeopleName();
//用基类获得变量函数，为子类更好的获得父类变量做好借口
char GetPeopleSex();

int GetPeopleAge();

private:

string Name; 
//姓名

char Sex; 
//性别

int Age; 
//年龄

};

People::People(string name,char sex,int age) 
//定义构造函数，对类里的私有成员赋值

{

Name=name;

Sex=sex;

Age=age;

}

string People::GetPeopleName() //返回Name的函数定义

{

return Name;

}

char People::GetPeopleSex() //返回Sex的函数定义

{

return Sex;

}

int People::GetPeopleAge() //返回Age的函数定义

{

return Age;

}

class Shepherd:public People//牧羊人类

{

public:

Shepherd(string name,char sex,int age,int rs);
//牧羊人类的构造函数1。

int GetRaisesheep();
//获得羊的数量

void HurtSheep(int number); //狗狗伤害小羊

void PrintShepherd(); //打印出牧羊人的信息

void ShepherdSendFood();

private:

int Raisesheep;
//牧羊人除了拥有人类的属性，还有自己的养了多少只羊

int SheepMeate; //羊肉

int SheepCheese; //奶酪

};

Shepherd::Shepherd(string name,char sex,int age,int rs):People(name,sex,age)//牧羊人类的构造函数。

{

Raisesheep=rs;

SheepMeate=10;

SheepCheese=10;

}

int Shepherd::GetRaisesheep() //获得饲养的羊的个数函数的定义

{

return Raisesheep;

}

void Shepherd::PrintShepherd() //打印出牧羊人的信息

{

cout<<"This is Shepherd message:"<<endl;

cout<<"Name :"<<GetPeopleName()<<endl;

cout<<"Sex :"<<GetPeopleSex()<<endl;

cout<<"Age :"<<GetPeopleAge()<<endl;

cout<<"Raisesheep :"<<Raisesheep<<endl;

cout<<"SheepMeate :"<<SheepMeate<<endl;

cout<<"SheepCheese :"<<SheepCheese<<endl;

}

void Shepherd::HurtSheep(int number) //狗伤羊的函数定义

{

Raisesheep-=number;

}

void Shepherd::ShepherdSendFood()

{

SheepMeate-=5;

SheepCheese-=5;

}

class Hunter:public People//猎人类

{

public:

Hunter(string name,char sex,int age,int ha,int dg);

void Dog_sheep();
//猎人的狗狗袭击羊群 

int GetHuntanimal();

void PrintHunt();

friend void CallJudge(); //友原函数

void HunterTieDogs();

void HunterSendFood();

private:

int Huntanimal;
//猎人除了拥有人类的属性，还有自己的打了多少只动物

int Dogs; 
//猎人还养了猎狗

};

Hunter::Hunter(string name,char sex,int age,int ha,int dg):People(name,sex,age)//猎人类的构造函数。

{

Huntanimal=ha;

Dogs=dg;

}

int Hunter::GetHuntanimal() //打猎的动物函数定义

{

return Huntanimal;

}

void Hunter::PrintHunt() //输出猎人的信息

{

cout<<"This is Hunter message:"<<endl;

cout<<"Name :"<<GetPeopleName()<<endl;

cout<<"Sex :"<<GetPeopleSex()<<endl;

cout<<"Age :"<<GetPeopleAge()<<endl;

cout<<"Everyday Huntanimal :"<<Huntanimal<<endl;

cout<<"Dogs :"<<Dogs<<endl;

}

void Hunter::HunterTieDogs()

{

cout<<"The hunter "<<GetPeopleName()<<"tie dogs in the cage ."<<endl;

}

void Hunter::HunterSendFood()

{

Huntanimal-=5;

}

class HunterSon:public Hunter

{

public:

HunterSon(string name,char sex,int age,int ha,int dg);

void HunterSonPlaySheep();

};

HunterSon::HunterSon(string name,char sex,int age,int ha,int dg):Hunter(name,sex,age,ha,dg)

{

}

void HunterSon::HunterSonPlaySheep()

{

cout<<"The HunterSon "<<GetPeopleName()<<" play little sheep ."<<endl;

}

class Judge:public People

{

public:

Judge(string name,char sex,int age);

friend void CallJudge();

void display(Shepherd &shepherd);

};

Judge::Judge(string name,char sex,int age):People(name,sex,age)

{

}

void Judge::display(Shepherd &shepherd)

{

cout<<"The Judge's name is :"<<GetPeopleName()<<endl;

cout<<"The Judge's sex is :"<<GetPeopleSex()<<endl;

cout<<"The Judge's age is :"<<GetPeopleAge()<<endl;

cout<<"The Judge call shepherd give hunter's son 3 sheep ."<<endl;

shepherd.HurtSheep(3);

}

void CallJudge(Shepherd &shepherd) //友原函数的定义

{

cout<<"The "<<shepherd.GetPeopleName()<<" shepherd call judge to judge the matter ."<<endl;

}

void operation(People &shepherd) //这一步体现多态的性质，子类通过引用的方式赋值给父类变量，子类可以调用父类的函数

{

cout<<"The dogs hurt "<<shepherd.GetPeopleName()<<" shepherd little sheep ."<<endl;

}

int main()

{

cout<<"The story begin ."<<endl;

cout<<"The Shepherd feed many sheep ."<<endl;

cout<<"The Hunter feed many dogs ."<<endl;

cout<<endl;

Shepherd shepherd("Mr.Shepherd",'M',23,100);//定义一个牧羊人对象。分别对牧羊人基础信息初始化。

shepherd.PrintShepherd();

cout<<endl;

Hunter hunter("Mr.Hunter",'M',23,10,10);

hunter.PrintHunt();

cout<<endl;



operation(shepherd);

shepherd.HurtSheep(1);//first,hurt 1 sheep

cout<<"The dogs first hurt 1 sheep and there are "<<shepherd.GetRaisesheep()<<" sheep ."<<endl; 

shepherd.HurtSheep(2);//second,hurt 2 sheep

cout<<"The dogs second hurt 2 sheep and there are "<<shepherd.GetRaisesheep()<<" sheep ."<<endl;

shepherd.HurtSheep(3);//third,hurt 3 sheep

cout<<"The dogs third hurt 3 sheep and there are "<<shepherd.GetRaisesheep()<<" sheep ."<<endl;

cout<<endl;



CallJudge(shepherd);

Judge judge("Mr.Judge",'M',23);

judge.display(shepherd);

cout<<endl;

HunterSon hunter1("Mr.Hunterson1",'M',10,0,10);

HunterSon hunter2("Mr.Hunterson2",'M',10,0,10);

HunterSon hunter3("Mr.Hunterson3",'M',10,0,10);

hunter1.HunterSonPlaySheep();

hunter2.HunterSonPlaySheep();

hunter3.HunterSonPlaySheep();

cout<<endl;

hunter.HunterTieDogs();

cout<<endl;

cout<<"The shepherd sheep no hurt and the sheep is "<<shepherd.GetRaisesheep()<<endl;



cout<<endl;

cout<<"The shepherd and the hunter give something each other ."<<endl;

cout<<"The last shepherd and sheep message is :"<<endl;

shepherd.ShepherdSendFood();

hunter.HunterSendFood();

shepherd.PrintShepherd();

hunter.PrintHunt();

cout<<endl;

cout<<"Last there are friends ."<<endl;

return 0;

}
