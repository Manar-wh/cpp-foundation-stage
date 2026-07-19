#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "clsStrings.h"
using namespace std;
class clsDate
{
private:
    short _Day;
    short _Month;
    short _Year;
public:

    clsDate() {
        *this = GetSystemDate();
    }

    clsDate(string Date) {
        vector <string> vDate;
        vDate = clsStrings::Split(Date, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    clsDate(short Day, short Month, short Year) {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(int DayOrder, int Year) {
        *this = GetDateFromDayOrderInYear(DayOrder, Year);
    }

    void setDay(short Day) {
        _Day = Day;
    }
    short getDay() {
        return _Day;
    }
    __declspec(property(get = getDay, put = setDay)) short Day;

    void setMonth(short Month) {
        _Month = Month;
    }
    short getMonth() {
        return _Month;
    }

    __declspec(property(get = getMonth, put = setMonth)) short Month;

    void setYear(short Year) {
        _Year = Year;
    }
    short getYear() {
        return _Year;
    }

    __declspec(property(get = getYear, put = setYear)) short Year;

    static string DateToString(clsDate Date) {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString() {
        return DateToString(*this);
    }

    void Print() {
        cout << DateToString() << endl;
    }

    static clsDate GetSystemDate() {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;

        return clsDate(Day, Month, Year);
    }

    static bool IsLeapYear(short Year) {

        return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
    }

    bool IsLeapYear() {

        return IsLeapYear(_Year);
    }

    static short NumberOfDaysInMonth(short Month, short Year) {

        if (Month < 1 || Month > 12)
        {
            return 0;
        }

        short arrDaysInMonth[12] = { 31 , 28, 31,30, 31 , 30 , 31 , 31, 30, 31 , 30, 31 };
        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (arrDaysInMonth[Month - 1]);
    }

    short NumberOfDaysInMonth() {

        return NumberOfDaysInMonth(_Month, _Year);
    }

    static int NumberOfDaysFromBeginning(short Day, short Month, short Year) {

        int TotalDays = 0;

        for (int i = 1; i < Month; i++)
        {
            short NumOfDays = NumberOfDaysInMonth(i, Year);
            TotalDays += NumOfDays;
        }

        TotalDays += Day;
        return TotalDays;
    }

    int NumberOfDaysFromBeginning() {
        return NumberOfDaysFromBeginning(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(int DateOrderInYear, short Year) {

        short Month = 1;
        int ReminingDays = DateOrderInYear;

        while (ReminingDays > NumberOfDaysInMonth(Month, Year))
        {
            ReminingDays -= NumberOfDaysInMonth(Month, Year);
            Month++;

        }
        return clsDate(ReminingDays, Month, Year);
    }

    clsDate GetDateFromDayOrderInYear(int DateOrderInYear) {
        return GetDateFromDayOrderInYear(DateOrderInYear, _Year);
    }

    static short NumberOfDays(short Year) {
        return IsLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDays() {
        return NumberOfDays(_Year);
    }

    static int NumberOfHours(short Year) {
        return NumberOfDays(Year) * 24;
    }

    int NumberOfHours() {
        return NumberOfHours(_Year);
    }

    static int NumberOfMinutes(short Year) {
        return NumberOfHours(Year) * 60;
    }

    int NumberOfMinutes() {
        return NumberOfMinutes(_Year);
    }

    static long long NumberOfSeconds(short Year) {
        return (long long)NumberOfMinutes(Year) * 60;
    }

    long long NumberOfSeconds() {
        return NumberOfSeconds(_Year);
    }

    static int NumberOfHoursInMonth(short Month, short Year) {
        return NumberOfDaysInMonth(Month, Year) * 24;
    }

    int NumberOfHoursInMonth(short Month) {
        return NumberOfHoursInMonth(Month, _Year);
    }

    static int NumberOfMinutesInMonth(short Month, short Year) {
        return NumberOfHoursInMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInMonth(short Month) {
        return NumberOfMinutesInMonth(Month, _Year);
    }

    static long long NumberOfSecondsInMonth(short Month, short Year) {
        return (long long)NumberOfMinutesInMonth(Month, Year) * 60;
    }

    long long NumberOfSecondsInMonth(short Month) {
        return NumberOfSecondsInMonth(Month, _Year);
    }

    static int DayOfWeekOrder(short Day, short Month, short Year) {

        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;

        int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }

    int DayOfWeekOrder() {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string FindDayName(short DayOrder) {

        string DaysOfTheWeek[7] = { "Sun","Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
        return DaysOfTheWeek[DayOrder];
    }

    string FindDayName() {
        return FindDayName(DayOfWeekOrder());
    }


    static string FindMonthName(short Month) {

        string NameOfMonths[12] = { "Jan", "Feb", "Mar", "Apr", "May",
            "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return NameOfMonths[Month - 1];
    }

    string FindMonthName() {
        return FindMonthName(_Month);
    }

    static void PrintMonthCalendar(short Month, short Year) {

        printf("\n-----------------%s-----------------\n", FindMonthName(Month).c_str());

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short NumberOfDays = NumberOfDaysInMonth(Month, Year);
        short DayOrder = DayOfWeekOrder(1, Month, Year);

        int i = 0;
        for (i = 0; i < DayOrder; i++)
        {
            printf("     ");
        }

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n _________________________________\n");
    }

    void PrintMonthCalendar() {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(short Year) {

        printf("\n ------------------------------------\n");
        printf("\t  Calender - %d", Year);
        printf("\n ------------------------------------\n");

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }
    }

    void PrintYearCalendar() {
        PrintYearCalendar(_Year);
    }

    static clsDate AddingDaysToDate(clsDate Date, int AddingDays) {
        int RemainingDays = AddingDays + NumberOfDaysFromBeginning(Date._Day, Date._Month, Date._Year);
        short Month = 1;

        while (true)
        {
            short NumberOfDays = NumberOfDaysInMonth(Month, Date._Year);

            if (RemainingDays > NumberOfDays)
            {
                RemainingDays -= NumberOfDays;
                Month++;

                if (Month > 12)
                {
                    Date._Year++;
                    Month = 1;
                }
            }
            else
            {
                Date._Day = RemainingDays;
                Date._Month = Month;
                break;
            }
        }

        return Date;
    }

    void AddingDays(int AddingDays) {
        *this = AddingDaysToDate(*this, AddingDays);
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
        return (Date1._Year < Date2._Year) ? true :
            (Date1._Year == Date2._Year) ?
            ((Date1._Month < Date2._Month) ? true :
                (Date1._Month == Date2._Month) ? (Date1._Day < Date2._Day) : false) : false;
    }

    bool IsDateBeforeDate2(clsDate Date2) {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
        return (Date1._Year == Date2._Year) ?
            ((Date1._Month == Date2._Month) ? (Date1._Day == Date2._Day) : false)
            : false;
    }

    bool IsDateEqualDate2(clsDate Date2) {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date) {
        return (Date._Day == NumberOfDaysInMonth(Date._Month, Date._Year));
    }

    bool IsLastDayInMonth() {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(clsDate Date) {
        return (Date._Month == 12);
    }

    bool IsLastMonthInYear() {
        return IsLastMonthInYear(*this);
    }

    static clsDate AddOneDayToDate(clsDate Date) {

        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date))
            {
                Date._Day = 1;
                Date._Month = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }
        return Date;
    }

    clsDate AddOneDayToDate() {
        return AddOneDayToDate(*this);
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2) {
        clsDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static int HowManyDaysBetweenTwoDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
        int Days = 0;
        short SawpFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SawpFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = AddOneDayToDate(Date1);
            Days++;
        }

        if (IncludeEndDay) {
            Days++;
        }

        return Days * SawpFlagValue;
    }

    int HowManyDaysBetweenTwoDates(clsDate Date2, bool IncludeEndDay = false) {
        return HowManyDaysBetweenTwoDates(*this, Date2, IncludeEndDay);
    }

    static int CalculateMyAgeInDays(clsDate MyBirthDate) {
        int MyAgeInDays;
        clsDate CurrentDate;
        MyAgeInDays = HowManyDaysBetweenTwoDates(MyBirthDate, CurrentDate);
        return MyAgeInDays;
    }

    int CalculateMyAgeInDays() {
        return CalculateMyAgeInDays(*this);
    }

    static clsDate IncreaseDateByXDays(clsDate& Date, int XDays) {
        for (int i = 0; i < XDays; i++)
        {
            Date = AddOneDayToDate(Date);
        }
        return Date;
    }

    clsDate IncreaseDateByXDays(int XDays) {
        return *this = clsDate::IncreaseDateByXDays(*this, XDays);
    }

    static clsDate IncreaseDateByOneWeek(clsDate& Date) {
        return IncreaseDateByXDays(Date, 7);
    }

    clsDate IncreaseDateByOneWeek() {
        return *this = clsDate::IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeek(clsDate& Date, int XWeek) {
        return IncreaseDateByXDays(Date, XWeek * 7);
    }

    clsDate IncreaseDateByXWeek(int XWeek) {
        return *this = clsDate::IncreaseDateByXWeek(*this, XWeek);
    }

    static clsDate IncreaseDateByOneMonth(clsDate& Date) {

        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    clsDate IncreaseDateByOneMonth() {
        return *this = clsDate::IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonth(clsDate& Date, int XMonth) {
        for (int i = 0; i < XMonth; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    clsDate IncreaseDateByXMonth(int XMonth) {
        return *this = clsDate::IncreaseDateByXMonth(*this, XMonth);
    }


    static clsDate IncreaseDateByOneYear(clsDate& Date) {

        return IncreaseDateByXMonth(Date, 12);
    }

    clsDate IncreaseDateByOneYear() {
        return *this = clsDate::IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYear(clsDate& Date, int XYear) {
        Date._Year += XYear;
        Date._Day = (Date._Month == 2 && Date._Day == 29 && !IsLeapYear(Date._Year)) ? 28 : Date._Day;
        return Date;
    }

    clsDate IncreaseDateByXYear(int XYear) {
        return *this = clsDate::IncreaseDateByXYear(*this, XYear);
    }

    static clsDate IncreaseDateByOneDecade(clsDate& Date) {
        return IncreaseDateByXYear(Date, 10);
    }
    clsDate IncreaseDateByOneDecade() {
        return *this = clsDate::IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecade(clsDate& Date, int XDecade) {
        Date._Year += (XDecade * 10);
        Date._Day = (Date._Month == 2 && Date._Day == 29 && !IsLeapYear(Date._Year)) ? 28 : Date._Day;
        return Date;
    }

    clsDate IncreaseDateByXDecade(int XDecade) {
        return *this = clsDate::IncreaseDateByXDecade(*this, XDecade);
    }

    static clsDate IncreaseDateByOneCentury(clsDate& Date) {
        return IncreaseDateByXYear(Date, 100);
    }

    clsDate IncreaseDateByOneCentury() {
        return *this = clsDate::IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate& Date) {
        return IncreaseDateByXYear(Date, 1000);
    }

    clsDate IncreaseDateByOneMillennium() {
        return *this = clsDate::IncreaseDateByOneMillennium(*this);
    }

    static clsDate DecreaseDateByOneDay(clsDate& Date) {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Year--;
            }
            else
            {
                Date._Month--;
            }
            Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
        }
        else
        {
            Date._Day--;
        }
        return Date;
    }

    clsDate DecreaseDateByOneDay() {
        return *this = clsDate::DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDays(clsDate& Date, int XDays) {
        for (int i = 0; i < XDays; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    clsDate DecreaseDateByXDays(int XDays) {
        return *this = clsDate::DecreaseDateByXDays(*this, XDays);
    }

    static clsDate DecreaseDateByOneWeek(clsDate& Date) {
        return DecreaseDateByXDays(Date, 7);
    }

    clsDate DecreaseDateByOneWeek() {
        return *this = clsDate::DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeek(clsDate& Date, int XWeek) {
        return DecreaseDateByXDays(Date, XWeek * 7);
    }

    clsDate DecreaseDateByXWeek(int XWeek) {
        return *this = clsDate::DecreaseDateByXWeek(*this, XWeek);
    }

    static clsDate DecreaseDateByOneMonth(clsDate& Date) {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
        {
            Date._Month--;
        }

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    clsDate DecreaseDateByOneMonth() {
        return *this = clsDate::DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonth(clsDate& Date, int XMonth) {
        for (int i = 0; i < XMonth; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    clsDate DecreaseDateByXMonth(int XMonth) {
        return *this = clsDate::DecreaseDateByXMonth(*this, XMonth);
    }

    static clsDate DecreaseDateByOneYear(clsDate& Date) {
        return DecreaseDateByXMonth(Date, 12);
    }

    clsDate DecreaseDateByOneYear() {
        return *this = clsDate::DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYear(clsDate& Date, int XYear) {
        for (int i = 0; i < XYear; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    clsDate DecreaseDateByXYear(int XYear) {
        return *this = clsDate::DecreaseDateByXYear(*this, XYear);
    }

    static clsDate DecreaseDateByXYearFaster(clsDate& Date, int XYear) {
        Date._Year -= XYear;
        Date._Day = (Date._Month == 2 && Date._Day == 29 && !IsLeapYear(Date._Year)) ? 28 : Date._Day;
        return Date;
    }

    clsDate DecreaseDateByXYearFaster(int XYear) {
        return *this = clsDate::DecreaseDateByXYearFaster(*this, XYear);
    }

    static clsDate DecreaseDateByOneDecade(clsDate& Date) {
        return DecreaseDateByXYear(Date, 10);
    }

    clsDate DecreaseDateByOneDecade() {
        return *this = clsDate::DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecade(clsDate& Date, int XDecade) {
        for (int i = 0; i < XDecade; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }

    clsDate DecreaseDateByXDecade(int XDecade) {
        return *this = clsDate::DecreaseDateByXDecade(*this, XDecade);
    }

    static clsDate DecreaseDateByOneCentury(clsDate& Date) {
        return DecreaseDateByXYearFaster(Date, 100);
    }

    clsDate DecreaseDateByOneCentury() {
        return *this = clsDate::DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate& Date) {
        return DecreaseDateByXYearFaster(Date, 1000);
    }

    clsDate DecreaseDateByOneMillennium() {
        return *this = clsDate::DecreaseDateByOneMillennium(*this);
    }
    static bool IsEndOfWeek(clsDate Date) {
        return (clsDate::DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6);
    }

    bool IsEndOfWeek() {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date) {
        short DayOrder = clsDate::DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        return (DayOrder == 5 || DayOrder == 6);
    }

    bool IsWeekEnd() {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date) {
        return !clsDate::IsWeekEnd(Date);
    }

    bool IsBusinessDay() {
        return IsBusinessDay(*this);
    }

    static int DaysUntilTheEndOfWeek(clsDate Date) {
        return 6 - clsDate::DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    int DaysUntilTheEndOfWeek() {
        return DaysUntilTheEndOfWeek(*this);
    }

    static int DaysUntilTheEndOfMonth(clsDate Date) {
        int DaysInMonth = clsDate::NumberOfDaysInMonth(Date.Month, Date.Year);
        return DaysInMonth - Date.Day;
    }

    int DaysUntilTheEndOfMonth() {
        return DaysUntilTheEndOfMonth(*this);
    }

    static int DaysUntilTheEndOfYear(clsDate Date) {
        short TotalDaysInYear = clsDate::IsLeapYear(Date.Year) ? 366 : 365;
        return TotalDaysInYear - clsDate::NumberOfDaysFromBeginning(Date.Day, Date.Month, Date.Year);
    }

    int DaysUntilTheEndOfYear() {
        return DaysUntilTheEndOfYear(*this);
    }
    static void VacationFrom(clsDate Date) {
        short DayOrder = clsDate::DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        std::cout << "\nVacation From " << clsDate::FindDayName(DayOrder)
            << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    }

    void VacationFrom() {
        clsDate::VacationFrom(*this);
    }

    static void VacationTo(clsDate Date) {
        short DayOrder = clsDate::DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
        std::cout << "\nVacation To " << clsDate::FindDayName(DayOrder)
            << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    }

    void VacationTo() {
        clsDate::VacationTo(*this);
    }

    static short CalculateVacationDays(clsDate Date1, clsDate Date2) {
        short Counter = 0;

        while (clsDate::IsDate1BeforeDate2(Date1, Date2))
        {
            if (!clsDate::IsWeekEnd(Date1))
            {
                Counter++;
            }
            Date1 = clsDate::AddOneDayToDate(Date1);
        }
        return Counter;
    }

    short CalculateVacationDays(clsDate Date2) {
        return clsDate::CalculateVacationDays(*this, Date2);
    }

    static clsDate CalculateReturnDate(clsDate Date, short VDays) {
        while (VDays > 0)
        {
            if (clsDate::IsBusinessDay(Date))
            {
                VDays--;
            }
            Date = clsDate::AddOneDayToDate(Date);
        }

        while (clsDate::IsWeekEnd(Date))
        {
            Date = clsDate::AddOneDayToDate(Date);
        }

        return Date;
    }

    clsDate CalculateReturnDate(short VDays) {
        return clsDate::CalculateReturnDate(*this, VDays);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
        return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
    }

    bool IsDateAfterDate2(clsDate Date2) {
        return clsDate::IsDate1AfterDate2(*this, Date2);
    }

    enum enCompare { Before = -1, Equal = 0, After = 1 };

    static enCompare CompareDates(clsDate Date1, clsDate Date2) {
        if (clsDate::IsDate1BeforeDate2(Date1, Date2)) return enCompare::Before;
        if (clsDate::IsDate1AfterDate2(Date1, Date2)) return enCompare::After;
        return enCompare::Equal;
    }

    enCompare CompareDates(clsDate Date2) {
        return clsDate::CompareDates(*this, Date2);
    }

    static bool IsValidDate(clsDate Date) {
        short NumOfDaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        return (Date.Day > 0 && Date.Day <= NumOfDaysInMonth) &&
            (Date.Month > 0 && Date.Month <= 12);
    }

    bool IsValidDate() {
        return clsDate::IsValidDate(*this);
    }

};
