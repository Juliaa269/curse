#include <iostream>
#include <string>
#include <stdio.h>
#include <ostream>
using namespace std;
class Person
{
protected:
	string fullname;
	int age;
	int height;
public:
	Person() :fullname(), age(), height() {}
	Person(const string& fullname, int age, int height)
	{
		this->fullname = fullname;
		this->age = age;
		this->height = height;
		if (age <= 0 || height < 50)
			throw invalid_argument("Age or Height is wrong.");
	}
	friend ostream& operator <<(ostream &out, const Person &p);
};
ostream& operator << (ostream &out, const Person &p)
{
	out << "Person: " << p.fullname << endl << "Возраст: " << p.age << " " << endl << "Рост: " << p.height << " см " << endl;
	return out;
}
class Student : public Person
{
private:
	int group;
	string faculty;
	int course;
	int number_of_excellent_ratings;
	int number_of_good_ratings;
	int number_of_satisfactory_ratings;
	int number_of_unsatisfactory_ratings;
	const double stipendia = 800.25;
	const double enhanced_stipendia = 1200.25;
	const int number_of_ratings = 10;
public:
	Student() : Person() {}
	Student(const string& fullname, int age, int height, int group, const string& faculty, int course, int number_of_excellent_ratings, int number_of_good_ratings, int number_of_satisfactory_ratings, int number_of_unsatisfactory_ratings) : Person(fullname, age, height)
	{
		this->group = group;
		this->faculty = faculty;
		this->course = course;
		this->number_of_excellent_ratings = number_of_excellent_ratings;
		this->number_of_good_ratings = number_of_good_ratings;
		this->number_of_satisfactory_ratings = number_of_satisfactory_ratings;
		this->number_of_unsatisfactory_ratings = number_of_unsatisfactory_ratings;
		if (group <= 0 || (course <= 0 || course > 7) || (number_of_excellent_ratings + number_of_good_ratings + number_of_satisfactory_ratings + number_of_unsatisfactory_ratings) > number_of_ratings)
			throw invalid_argument("Student: Group or course or rating is wrong");
		if (age <= 16 || height<90)
			throw invalid_argument("Student's age or height is wrong.");
	}
	double count_stipendia()
	{
		if (number_of_good_ratings == 0 && number_of_satisfactory_ratings == 0 && number_of_unsatisfactory_ratings == 0 && number_of_excellent_ratings == number_of_ratings)
			return enhanced_stipendia;
		else if (number_of_unsatisfactory_ratings == 0 && (number_of_excellent_ratings + number_of_good_ratings) >= number_of_satisfactory_ratings && (number_of_excellent_ratings + number_of_good_ratings + number_of_satisfactory_ratings) == number_of_ratings)
			return stipendia;
		else
			return 0.0;
	}


	//написать методы...



	friend ostream& operator << (ostream &out, const Student &p);
};
ostream& operator << (ostream &out, const Student &p)
{
	out << "Student: " << p.fullname << endl <<"Возраст: " <<p.age << " " << endl << "Рост: " << p.height << " см " << endl << "Группа: " << p.group << endl << "Факультет: " << p.faculty << endl << "Курс: " << p.course << endl << "Оценки: отлично - " << p.number_of_excellent_ratings << ", хорошо - " << p.number_of_good_ratings << ", удовлетворительно - " << p.number_of_satisfactory_ratings << ", неудовлетворительно - " << p.number_of_unsatisfactory_ratings << endl;
	return out;
}
class Curator : public Person
{
private:
	int group;
	int course;
	string faculty;
public:
	Curator() : Person() {}
	Curator(const string& fullname, int age, int height, int group, int course, const string& faculty) : Person(fullname, age, height)

	{
		this->group = group;
		this->course = course;
		this->faculty = faculty;
		if (group <= 0 || course <= 0 || course > 7)
			throw invalid_argument("Curator: Group or Course is wrong.");
		if (age < 20 || height < 90)
			throw invalid_argument("Curator's age or height is wrong.");
	}
	friend ostream& operator << (ostream &out, const Curator &p);
};
ostream& operator << (ostream &out, const Curator &p)
{
	out << "Curator: " << p.fullname << endl << "Возраст: " << p.age << " " << endl << "Рост: " << p.height << " см " << endl << "Группа: " << p.group << endl << "Факультет: " << p.faculty << endl << "Курс: " << p.course << endl;
	return out;
}
class Decan : public Person
{
private:
	string faculty;
public:
	string getFaculty()
	{
		return faculty;
	}
	Decan() : Person() {}
	Decan(const string& fullname, int age, int height, const string& faculty) : Person(fullname, age, height)
	{
		this->faculty = faculty;
		if (age <= 35 || height <90)
			throw invalid_argument("Decan's age or height is wrong.");
	}

	friend ostream& operator << (ostream &out, const Decan &p);
};
ostream& operator << (ostream &out, const Decan &p)
{
	out << "Decan: " << p.fullname << endl << "Возраст: " << p.age << " " << endl << "Рост: " << p.height << " см " << endl << "Факультет: " << p.faculty << endl;
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		Student p("Kuznekov Valeriy Victorovich", 18, 192, 1, "MEO", 2, 3, 4, 3, 0);
		Curator y("Lavrin Oleg Sergeevich", 54, 179, 1, 5, "FIT");
		Decan l("Kunush Elizaveta Victorovna", 36, 176, "MEO");
		Person Vasya("Gavrilov Vasya Pet`kin", 45, 178);
		cout << p << "\n" << y << "\n" << l << "\n" << Vasya << "\n" << "Стипендия: " << p.count_stipendia() <<" грн."<< "\n" << endl;
	}
	catch (const invalid_argument& r)
	{
		cout << "Invalid argument: " << r.what() << endl;
	}
	system("pause");
}