#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>
#include <utility> 
#include <vector>
#include <ctime>

using namespace std;

void inc(string&, int);

vector<pair<string, string>> hiragana{};


int main(int argc, char** argv)
{

	hiragana.push_back(make_pair("あ", "a"));
	hiragana.push_back(make_pair("え", "e"));
	hiragana.push_back(make_pair("い", "i"));
	hiragana.push_back(make_pair("お", "o"));
	hiragana.push_back(make_pair("う", "u"));

	hiragana.push_back(make_pair("こ", "ko"));
	hiragana.push_back(make_pair("か", "ka"));
	hiragana.push_back(make_pair("く", "ku"));
	hiragana.push_back(make_pair("き", "ki"));
	hiragana.push_back(make_pair("け", "ke"));

	hiragana.push_back(make_pair("さ", "sa"));
	hiragana.push_back(make_pair("す", "su"));
	//hiragana.push_back(make_pair("し", "si"));
	hiragana.push_back(make_pair("せ", "se"));
	hiragana.push_back(make_pair("そ", "so"));

	hiragana.push_back(make_pair("と", "to"));
	hiragana.push_back(make_pair("た", "ta"));
	//hiragana.push_back(make_pair("ち", "ti"));
	//hiragana.push_back(make_pair("つ", "tu"));
	hiragana.push_back(make_pair("て", "te"));

	hiragana.push_back(make_pair("な", "na"));
	hiragana.push_back(make_pair("に", "ni"));
	hiragana.push_back(make_pair("ぬ", "nu"));
	hiragana.push_back(make_pair("ね", "ne"));
	hiragana.push_back(make_pair("の", "no"));

	hiragana.push_back(make_pair("は", "ha"));
	hiragana.push_back(make_pair("ひ", "hi"));
	hiragana.push_back(make_pair("ふ", "hu"));
	hiragana.push_back(make_pair("へ", "he"));
	hiragana.push_back(make_pair("ほ", "ho"));

	hiragana.push_back(make_pair("ま", "ma"));
	hiragana.push_back(make_pair("み", "mi"));
	hiragana.push_back(make_pair("む", "mu"));
	hiragana.push_back(make_pair("め", "me"));
	hiragana.push_back(make_pair("も", "mo"));

	hiragana.push_back(make_pair("や", "ya"));
	hiragana.push_back(make_pair("ゆ", "yu"));
	hiragana.push_back(make_pair("よ", "yo"));

	hiragana.push_back(make_pair("ら", "ra"));
	hiragana.push_back(make_pair("り", "ri"));
	hiragana.push_back(make_pair("る", "ru"));
	hiragana.push_back(make_pair("れ", "re"));
	hiragana.push_back(make_pair("ろ", "ro"));

	hiragana.push_back(make_pair("わ", "wa"));
	hiragana.push_back(make_pair("を", "wo"));

	hiragana.push_back(make_pair("ざ", "za"));
	hiragana.push_back(make_pair("じ", "zi"));
	hiragana.push_back(make_pair("ず", "zu"));
	hiragana.push_back(make_pair("ぜ", "ze"));
	hiragana.push_back(make_pair("ぞ", "zo"));

	hiragana.push_back(make_pair("が", "ga"));
	hiragana.push_back(make_pair("ぎ", "gi"));
	hiragana.push_back(make_pair("ぐ", "gu"));
	hiragana.push_back(make_pair("げ", "ge"));
	hiragana.push_back(make_pair("ご", "go"));

	hiragana.push_back(make_pair("だ", "da"));
	hiragana.push_back(make_pair("ぢ", "di"));
	hiragana.push_back(make_pair("づ", "du"));
	hiragana.push_back(make_pair("で", "de"));
	hiragana.push_back(make_pair("ど", "do"));

	hiragana.push_back(make_pair("ば", "ba"));
	hiragana.push_back(make_pair("び", "bi"));
	hiragana.push_back(make_pair("ぶ", "bu"));
	hiragana.push_back(make_pair("べ", "be"));
	hiragana.push_back(make_pair("ぼ", "bo"));

	hiragana.push_back(make_pair("ぱ", "pa"));
	hiragana.push_back(make_pair("ぷ", "pu"));
	hiragana.push_back(make_pair("ぴ", "pi"));
	hiragana.push_back(make_pair("ぺ", "pe"));
	hiragana.push_back(make_pair("ぽ", "po"));

	hiragana.push_back(make_pair("ん", "n"));
	
	hiragana.push_back(make_pair("ち", "chi"));
	hiragana.push_back(make_pair("し", "shi"));
	hiragana.push_back(make_pair("つ", "tsu"));


	cout << "\n\nPractice Hiragana, type \"q\", \"quit\", or \"exit\" to quit, or \"help\" for a reference list. If you want to reveal the answer, type \"ans\"" << "\n" << "Ganbatte!\n\n";
	string in;
	while(in != "exit" && in != "quit" && in != "q")
	{
		srand(time(NULL));
		int num = rand() % hiragana.size();
		cout << "\n" << hiragana[num].first << "\n\n";
		cin >> in;
		while(in != hiragana[num].second)
		{
			if(in == "ans")
			{
				cout << "\nThe answer is: " << hiragana[num].first << " = " << hiragana[num].second << "\n\n";
				break;
			}
			else if(in == "help")
			{
				for(int i = 0; i < hiragana.size(); ++i)
				{
					cout << hiragana[i].first << " = " << hiragana[i].second << "		";
					if(i % 5 == 4)
					{
						cout << "\n";
					}
				}

				cout << "\n\nTry again\n\n" << hiragana[num].first << "\n\n";
				cin >> in;
			}
			else if(in == "exit" || in == "quit" || in == "q")
			{
				break;
			}
			else
			{
				inc(in, num);
			}
		}
		if(in == "ans")
		{
			cout << "\nNext hiragana: \n";
		}
		else if(in != "exit" && in != "quit" && in != "q")
		{
			cout << "\n\nHai!\n\n";
		}
	}

	cout << "\nOtsukaresama deshita! Sayonara! Nyaaaa~\n\n";
}

void inc(string& input, int num)
{
	cout << "\nChigau, pls try again" << "\n\n";
	cout << "\n" << hiragana[num].first << "\n\n";
	cin >> input;
}
