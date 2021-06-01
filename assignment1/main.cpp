// compiling instruction: g++ main.cpp StringSet.cpp -std=c++11

#include "StringSet.h"

#include <iostream>

using std::cout;
using std::endl;

// include this in header file for testing
//void printStringSet(string varname) const;

void StringSet::printStringSet(string varname) const
{
	cout << varname << " = { ";
	for (int i = 0; i < curSize; i++) 
	{
		// at the last element, don't print "," after
		if (i == curSize - 1) {
			cout << sset[i];
		}
		else {
			cout << sset[i] << ", ";
		}
	}
	cout << " }" << endl;
	cout << "maxSize = " << maxSize << endl;
	cout << "curSize = " << curSize << endl;
	cout << endl;
}


void basicTest()
{
	StringSet sset1;
	sset1.insert("cat");
	sset1.insert("bat");
	sset1.insert("rat");
	cout << "insert success: " << sset1.insert("badger") << endl;

	StringSet sset2;
	sset2.insert("elephant");
	sset2.insert("bat");
	sset2.insert("hamster");
	sset2.insert("weasel");
	sset2.remove("weasel");
	cout << "index of weasel = " << sset2.find("weasel") << endl;

	// Use the copy constructor to build a StringSet with sset1 U sset2
	StringSet sset3(sset1.unions(sset2));

	// Use overloaded assignment operator to make a StringSet with sset2 int sset1
	StringSet sset4;
	sset4 = sset2.intersection(sset1);
	// Use overloaded assignment operator to make a StringSet with sset2 - sset1
	sset4 = sset2.difference(sset1);

	cout << "end basic test" << endl;
}


void basicTestv2()
{
	StringSet sset1;
	sset1.insert("cat");
	sset1.insert("bat");
	sset1.insert("rat");
	cout << "insert success: " << sset1.insert("badger") << endl;

	StringSet sset2;
	sset2.insert("elephant");
	sset2.insert("bat");
	sset2.insert("hamster");
	sset2.insert("weasel");
	cout << "index of weasel = " << sset2.find("weasel") << endl;
	sset2.remove("weasel");
	cout << "index of weasel = " << sset2.find("weasel") << endl;

	//// Use the copy constructor to build a StringSet with sset1 U sset2
	StringSet sset3(sset1.intersection(sset2));

	//// Use overloaded assignment operator to make a StringSet with sset2 int sset1
	StringSet sset4;
	sset4 = sset2.intersection(sset1);
	// use overloaded assignment operator to make a stringset with sset2 - sset1
	sset4 = sset2.difference(sset1);


	sset1.printStringSet("sset1");

	sset2.printStringSet("sset2");

	sset3.printStringSet("sset3");

	sset4.printStringSet("sset4");

	cout << "end basic test ..." << endl;
}


void insert_remove_size_test()
{
	// empty sset
	StringSet ss1;
	ss1.printStringSet("ss1");
	cout << "tesing size of ss1 ... (size: " << ss1.size() << " )" << endl;
	cout << "Removing cat ..." << endl;
	ss1.remove("cat");
	ss1.printStringSet("ss1");
	cout << "Finding cat ... (found at index: " << ss1.find("cat") << " )" << endl;

	cout << "inserting cat ... (status: " << ss1.insert("cat") << " )" <<endl;
	cout << "inserting cat ... (status: " << ss1.insert("cat") << " )" << endl;
	cout << "inserting dog ... (status: " << ss1.insert("dog") << " )" << endl;
	cout << "inserting bird ... (status: " << ss1.insert("bird") << " )" << endl;
	cout << "Finding cat ... (found at index: " << ss1.find("cat") << " )" << endl;
	cout << "Finding dog ... (found at index: " << ss1.find("dog") << " )" << endl;
	cout << "Finding monkey ... (found at index: " << ss1.find("monkey") << " )" << endl;

	ss1.printStringSet("ss1");
	cout << "Removing cat ..." << endl;
	ss1.remove("cat");
	ss1.printStringSet("ss1");

	ss1.remove("dog");
	ss1.remove("bird");
	ss1.remove("cat");
	ss1.printStringSet("ss1");

	// assuming empty string is considered one string
	cout << "inserting \"\" ... (status: " << ss1.insert("") << " )" << endl;
	ss1.printStringSet("ss1");

	StringSet ss2;
	cout << "inserting cat ... (status: " << ss2.insert("cat") << " )" << endl;
	cout << "inserting dog ... (status: " << ss2.insert("dog") << " )" << endl;
	cout << "inserting bird ... (status: " << ss2.insert("bird") << " )" << endl;
	cout << "inserting bird ... (status: " << ss2.insert("monkey") << " )" << endl;
	cout << "inserting bird ... (status: " << ss2.insert("bear") << " )" << endl;
	ss2.printStringSet("ss2");
	cout << "tesing size of ss2 ... (size: " << ss2.size() << " )" << endl;
}


void copytest()
{
	StringSet ss1;
	ss1.printStringSet("ss1");
	cout << "inserting cat ... (status: " << ss1.insert("cat") << " )" << endl;
	cout << "inserting dog ... (status: " << ss1.insert("dog") << " )" << endl;
	cout << "inserting bear ... (status: " << ss1.insert("bear") << " )" << endl;
	ss1.printStringSet("ss1");

	cout << "Copying ss1 to ss2 using copy constructor ... " << endl;
	StringSet ss2(ss1);
	ss2.printStringSet("ss2");

	cout << "Copying ss1 to ss3 using overloaded assignment operator... " << endl;
	StringSet ss3 = ss1;
	ss3.printStringSet("ss3");

	cout << "Copying ss1 to ss4 using overloaded assignment operator... " << endl;
	StringSet ss4;
	ss4 = ss1;
	ss4.printStringSet("ss4");

	cout << "inserting monkey ... (status: " << ss1.insert("monkey") << " )" << endl;
	cout << "Copying ss1 to ss4, ss5, ss6 using overloaded assignment operator... " << endl;
	StringSet ss5;
	StringSet ss6;
	ss6 = ss5 = ss4 = ss1;
	ss1.printStringSet("ss1");
	ss4.printStringSet("ss4");
	ss5.printStringSet("ss5");
	ss6.printStringSet("ss6");


	cout << "Removing cat ..." << endl;
	ss1.remove("cat");
	cout << "Copying ss1 to ss6, ss7 using overloaded assignment operator... " << endl;
	StringSet ss7 = ss6 = ss1;
	ss1.printStringSet("ss1");
	ss6.printStringSet("ss6");
	ss7.printStringSet("ss7");
	cout << "tesing size of ss7 ... (size: " << ss7.size() << " )" << endl;

	cout << "end copy test ..." << endl;
}

void union_intsec_diff_test() 
{
	StringSet ss1, ss2, ss3, ss4, ss5, ss6, ss7, ss8, ss9, ss10, ss11, ss12;
	StringSet res1, res2, res3, res4, res5, res6, res7;

	cout << "intialized ss1 to ss12 and res1 to res7 as all empty ..." << endl;

	cout << "for ss3 ..." << endl;
	cout << "inserting cat ... (status: " << ss3.insert("cat") << " )" << endl;
	cout << "inserting dog ... (status: " << ss3.insert("dog") << " )" << endl;
	cout << "inserting rabbit ... (status: " << ss3.insert("rabbit") << " )" << endl;
	cout << "inserting bird ... (status: " << ss3.insert("bird") << " )" << endl;
	cout << "inserting bear ... (status: " << ss3.insert("bear") << " )" << endl;

	cout << "for ss4 ..." << endl;
	cout << "inserting cat ... (status: " << ss4.insert("cat") << " )" << endl;
	cout << "inserting dog ... (status: " << ss4.insert("dog") << " )" << endl;
	cout << "inserting rabbit ... (status: " << ss4.insert("rabbit") << " )" << endl;
	cout << "inserting human ... (status: " << ss4.insert("human") << " )" << endl;
	cout << "inserting eagle ... (status: " << ss4.insert("eagle") << " )" << endl;

	ss1.printStringSet("ss1");
	ss2.printStringSet("ss2");
	ss3.printStringSet("ss3");
	ss4.printStringSet("ss4");



	cout << "unions test ..." << endl << endl;

	cout << "res1 = union of ss1 and ss2 ..." << endl;
	res1 = ss1.unions(ss2);
	res1.printStringSet("res1");

	cout << "res2 = union of ss1 and ss1 ..." << endl;
	res2 = ss1.unions(ss1);
	res2.printStringSet("res2");

	cout << "res3 = union of ss3 and ss1 ..." << endl;
	res3 = ss3.unions(ss1);
	res3.printStringSet("res3");

	cout << "res3 = union of ss1 and ss3 ..." << endl;
	res3 = ss1.unions(ss3);
	res3.printStringSet("res3");

	cout << "res4 = union of ss3 and ss4 ..." << endl;
	res4 = ss3.unions(ss4);
	res4.printStringSet("res4");




	cout << "intersection test ..." << endl << endl;

	cout << "res1 = intersection of ss1 and ss2 ..." << endl;
	res1 = ss1.intersection(ss2);
	res1.printStringSet("res1");

	cout << "res2 = intersection of ss1 and ss1 ..." << endl;
	res2 = ss1.intersection(ss1);
	res2.printStringSet("res2");

	cout << "res3 = intersection of ss3 and ss1 ..." << endl;
	res3 = ss3.intersection(ss1);
	res3.printStringSet("res3");

	cout << "res3 = intersection of ss1 and ss3 ..." << endl;
	res3 = ss1.intersection(ss3);
	res3.printStringSet("res3");

	cout << "res4 = intersection of ss3 and ss4 ..." << endl;
	res4 = ss3.intersection(ss4);
	res4.printStringSet("res4");




	cout << "difference test ..." << endl << endl;

	cout << "res1 = difference of ss1 and ss2 ..." << endl;
	res1 = ss1.difference(ss2);
	res1.printStringSet("res1");

	cout << "res2 = difference of ss1 and ss1 ..." << endl;
	res2 = ss1.difference(ss1);
	res2.printStringSet("res2");

	cout << "res3 = difference of ss3 and ss1 ..." << endl;
	res3 = ss3.difference(ss1);
	res3.printStringSet("res3");

	cout << "res3 = difference of ss1 and ss3 ..." << endl;
	res3 = ss1.difference(ss3);
	res3.printStringSet("res3");

	cout << "res4 = difference of ss3 and ss4 ..." << endl;
	res4 = ss3.difference(ss4);
	res4.printStringSet("res4");

	cout << "res5 = difference of ss4 and ss3 ..." << endl;
	res5 = ss4.difference(ss3);
	res5.printStringSet("res5");

}



int main()
{
	cout << "testing assignment 1 =====================================================" << endl << endl;

	cout << endl << "------------------------- basic test ---------------------------------------" << endl;
	basicTest();

	cout << endl << "------------------------- basic test v2 --------------------------------------" << endl;
	basicTestv2();

	cout << endl << "------------------------- insert remove size test --------------------------------------" << endl;
	insert_remove_size_test();

	cout << endl << "-------------------------- copy test --------------------------------------" << endl;
	copytest();

	cout << endl << "-------------------------- union intersection difference test --------------------------------------" << endl;
	union_intsec_diff_test();

	cout << "ending testing assignment 1 =====================================================" << endl << endl;
    return 0;
}