#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class Date
{
	private:
		int year;
		int month;
		int day;
		static int daysofmonth[2][12];
		bool isL()
		{
			if(year%400==0)
			{
				return true;
			}else
			{
				if(year%4==0)
				{
					if(year%100==0)
						return false;
					else
						return true;
				}
				return false;
			}
		}
	public:
		Date():year(0),month(0),day(0){}
		Date(const Date& date):year(date.year),month(date.month),day(date.day){}
		Date(int y,int m,int d):year(y),month(m),day(d){}
		~Date(){};
		void print()const{
			cout<<year<<'.'<<month<<'.'<<day<<endl;
		}
		void nextday(){
			if(day>=daysofmonth[isL()][month-1])
			{
				day=1;
				if(month==12)
				{
					month=1;
					++year;
				}
				else
				{
					++month;
				}
			}
			else
				++day;
		}
		void set(int y,int m,int d){
			year=y;
			month=m;
			day=d;
		}
};
int Date::daysofmonth[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	Date mydate;
	mydate.print();
	mydate.set(2016,2,4);
	mydate.print();
	mydate.set(2016,2,29);
	mydate.print();
	mydate.nextday();
	mydate.print();
	mydate.nextday();
	mydate.print();
	return 0;
}
