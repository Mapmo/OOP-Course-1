#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
unsigned counter = 0;
struct Option
{
	Option(const std::string&, const double);
	double val = 0;
	std::string text;
};
Option::Option(const std::string& txt, const double val) : text(txt), val(val)
{
}
class Question
{
public:
	Question(const std::string&);
	void AddOption(const std::string&, const double);
	void AskQuestion();
	int AnswerQuestion();
private:
	std::string m_Question;
	std::vector<Option>m_Answers;
	double m_Score = 0;
};
void Question::AddOption(const std::string& rhs, const double val)
{
	Option opt(rhs, val);
	m_Answers.push_back(opt);
}
Question::Question(const::std::string& task) : m_Question(task)
{
}
int Randomize(const int i)
{
	return std::rand() % i;
}
void Question::AskQuestion()
{
	std::cout << m_Question << "\n\n";
	std::srand(unsigned(std::time(0)));
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		std::swap(m_Answers[Randomize(m_Answers.size())], m_Answers[Randomize(m_Answers.size())]);
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		char ind = i + 65;
		std::cout << ind << ' ' << m_Answers[i].text << '\n';
	}
}

int Question::AnswerQuestion()
{
	char tmp = 'v';
	unsigned tmpToInt;
	std::cin >> tmp;
	tmpToInt = tmp;
	do
	{
		if (tmpToInt < 97)
			tmpToInt -= 65;
		else
			tmpToInt -= 97;
		m_Score += m_Answers[tmpToInt].val;
		std::cin >> tmp;
		tmpToInt = tmp;
	} while (tmp != 's' && tmp != 'S');
	std::cout << "Rezultat: " << m_Score << "\nVeren otgovor(i): ";
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		if (m_Answers[i].val > 0)
		{
			std::cout << char(i + 65) << ' ';
		}
	}
	std::cout << "\nVavedi nqkoi simvol";
	if (m_Score > 0)
	{
		counter++;
	}
	return m_Score;
}
int main()
{
	std::cout << "Test 1 po UK\nIzgotven ot Mapmo i Dakata\n";
	std::cout << "Za da otgovorite na nqkoi vupros vavedete bukvata(bukvite) i kogato ste gotovi vavedete 's'\n";
	std::cout << "Suobrazete se kak raboti std::cin\nAko jelaete simulaciq bez povtorni opiti natisnete r\nAko jelaete vuprosite, koito oburkate da se zapazvat natisnete proizvolen buton\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q0("Koe ot izbroenite e definiciq na Error?");
	q0.AddOption("Nekorektna stypka, proces ili definiciq na danni v kompyutyrna programa", -1);
	q0.AddOption("Nesposobnostta na sistemata ili komponenta da izvyrshi jelanata funkcionalnost v ramkite na specificiranite iziskvaniq na proizvoditelnost", -1);
	q0.AddOption("Choveshko vyzdeystvie, koeto vodi do nekorekten rezultat", 1);
	exam.push_back(q0);

	Question q1("Koe ot izbroenite e definiciq na Fault?");
	q1.AddOption("Nekorektna stypka, proces ili definiciq na danni v kompyutyrna programa", 1);
	q1.AddOption("Nesposobnostta na sistemata ili komponenta da izvyrshi jelanata funkcionalnost v ramkite na specificiranite iziskvaniq na proizvoditelnost", -1);
	q1.AddOption("Choveshko vyzdeystvie, koeto vodi do nekorekten rezultat", -1);
	exam.push_back(q1);

	Question q2("Koe ot izbroenite e definiciq na Failure?");
	q2.AddOption("Nekorektna stypka, proces ili definiciq na danni v kompyutyrna programa", -1);
	q2.AddOption("Nesposobnostta na sistemata ili komponenta da izvyrshi jelanata funkcionalnost v ramkite na specificiranite iziskvaniq na proizvoditelnost", 1);
	q2.AddOption("Choveshko vyzdeystvie, koeto vodi do nekorekten rezultat", -1);
	exam.push_back(q2);
	
	Question q3("Каква е връзката между понятията повреда, грешка и отказ?");
	q3.AddOption("Повреда → Грешка → Отказ ", -1);
	q3.AddOption("Грешка → Повреда → Отказ ", 1);
	q3.AddOption("Отказ → Повреда → Грешка ", -1);
	exam.push_back(q3);
	
	Question q4("При коя фаза от тестовия процес се избират метрики и модели?");
	q4.AddOption("Тестово планиране", 1);
	q4.AddOption("Изпълнение на тестове и наблюдения", -1);
	q4.AddOption("Анализ и проследяване ", -1);
	exam.push_back(q4);
	
	Question q6("?При коя фаза от тестовия процес се дефинират тестовите сценарии?");
	q6.AddOption("Изпълнение на тестовете и наблюдение" , -1);
	q6.AddOption("Тестово планиране и подготовка" , 1);
	q6.AddOption("Анализ и проследяване" , -1);
	exam.push_back(q6);
	
	Question q7("Коя от следните дейности НЕ се изпълнява при подготовка на тестовите сценарии??");
	q7.AddOption("Конструиране на нови тестови сценарии", -1);
	q7.AddOption("Автоматично генериране на тестови сценарии", -1);
	q7.AddOption("Избор на тестови сценарии от съществуващи такива", -1);
	q7.AddOption("Дефиниране на тестова цел", 1);
	exam.push_back(q7);
	
	Question q8("Коя от следните дейности НЕ се извършва при функционалното тестване?");
	q8.AddOption("Наблюдение на външното поведение на софтуерната система", -1);
	q8.AddOption("Дебъгване на софтуерната система", 1);
	q8.AddOption("Създаване на формални тестови модели", -1);
	exam.push_back(q8);
	
	Question q9("?")
	q9.AddOption("", -1)
	q9.AddOption("", -1)
	q9.AddOption("", -1)
	q9.AddOption("", -1)
	
	Question q10("?")
	q10.AddOption("", -1)
	q10.AddOption("", -1)
	q10.AddOption("", -1)
	q10.AddOption("", -1)
	
	Question q11("?")
	q11.AddOption("", -1)
	q11.AddOption("", -1)
	q11.AddOption("", -1)
	q11.AddOption("", -1)
	
	Question q12("?")
	q12.AddOption("", -1)
	q12.AddOption("", -1)
	q12.AddOption("", -1)
	q12.AddOption("", -1)
	
	Question q13("?")
	q13.AddOption("", -1)
	q13.AddOption("", -1)
	q13.AddOption("", -1)
	q13.AddOption("", -1)
	
	Question q14("?")
	q14.AddOption("", -1)
	q14.AddOption("", -1)
	q14.AddOption("", -1)
	q14.AddOption("", -1)
	
	Question q15("?")
	q15.AddOption("", -1)
	q15.AddOption("", -1)
	q15.AddOption("", -1)
	q15.AddOption("", -1)
	
	Question q16("?")
	q16.AddOption("", -1)
	q16.AddOption("", -1)
	q16.AddOption("", -1)
	q16.AddOption("", -1)
	
	Question q17("?")
	q17.AddOption("", -1)
	q17.AddOption("", -1)
	q17.AddOption("", -1)
	q17.AddOption("", -1)
	
	Question q18("?")
	q18.AddOption("", -1)
	q18.AddOption("", -1)
	q18.AddOption("", -1)
	q18.AddOption("", -1)
	
	Question q19("?")
	q19.AddOption("", -1)
	q19.AddOption("", -1)
	q19.AddOption("", -1)
	q19.AddOption("", -1)
	
	Question q20("?")
	q20.AddOption("", -1)
	q20.AddOption("", -1)
	q20.AddOption("", -1)
	q20.AddOption("", -1)
	
	Question q21("?")
	q21.AddOption("", -1)
	q21.AddOption("", -1)
	q21.AddOption("", -1)
	q21.AddOption("", -1)
	
	Question q22("?")
	q22.AddOption("", -1)
	q22.AddOption("", -1)
	q22.AddOption("", -1)
	q22.AddOption("", -1)
	
	Question q23("?")
	q23.AddOption("", -1)
	q23.AddOption("", -1)
	q23.AddOption("", -1)
	q23.AddOption("", -1)
	
	Question q24("?")
	q24.AddOption("", -1)
	q24.AddOption("", -1)
	q24.AddOption("", -1)
	q24.AddOption("", -1)
	
	Question q25("?")
	q25.AddOption("", -1)
	q25.AddOption("", -1)
	q25.AddOption("", -1)
	q25.AddOption("", -1)
	
	Question q26("?")
	q26.AddOption("", -1)
	q26.AddOption("", -1)
	q26.AddOption("", -1)
	q26.AddOption("", -1)
	
	Question q27("?")
	q27.AddOption("", -1)
	q27.AddOption("", -1)
	q27.AddOption("", -1)
	q27.AddOption("", -1)
	
	Question q28("?")
	q28.AddOption("", -1)
	q28.AddOption("", -1)
	q28.AddOption("", -1)
	q28.AddOption("", -1)
	
	Question q29("?")
	q29.AddOption("", -1)
	q29.AddOption("", -1)
	q29.AddOption("", -1)
	q29.AddOption("", -1)
	
	Question q30("?")
	q30.AddOption("", -1)
	q30.AddOption("", -1)
	q30.AddOption("", -1)
	q30.AddOption("", -1)
	
	Question q31("?")
	q31.AddOption("", -1)
	q31.AddOption("", -1)
	q31.AddOption("", -1)
	q31.AddOption("", -1)
	
	Question q32("?")
	q32.AddOption("", -1)
	q32.AddOption("", -1)
	q32.AddOption("", -1)
	q32.AddOption("", -1)
	
	Question q33("?")
	q33.AddOption("", -1)
	q33.AddOption("", -1)
	q33.AddOption("", -1)
	q33.AddOption("", -1)
	
	Question q34("?")
	q34.AddOption("", -1)
	q34.AddOption("", -1)
	q34.AddOption("", -1)
	q34.AddOption("", -1)
	
	Question q35("?")
	q35.AddOption("", -1)
	q35.AddOption("", -1)
	q35.AddOption("", -1)
	q35.AddOption("", -1)
	
	Question q36("?")
	q36.AddOption("", -1)
	q36.AddOption("", -1)
	q36.AddOption("", -1)
	q36.AddOption("", -1)
	
	Question q37("?")
	q37.AddOption("", -1)
	q37.AddOption("", -1)
	q37.AddOption("", -1)
	q37.AddOption("", -1)
	
	Question q38("?")
	q38.AddOption("", -1)
	q38.AddOption("", -1)
	q38.AddOption("", -1)
	q38.AddOption("", -1)
	
	Question q39("?")
	q39.AddOption("", -1)
	q39.AddOption("", -1)
	q39.AddOption("", -1)
	q39.AddOption("", -1)
	
	Question q40("?")
	q40.AddOption("", -1)
	q40.AddOption("", -1)
	q40.AddOption("", -1)
	q40.AddOption("", -1)
	
	Question q41("?")
	q41.AddOption("", -1)
	q41.AddOption("", -1)
	q41.AddOption("", -1)
	q41.AddOption("", -1)
	
	Question q42("?")
	q42.AddOption("", -1)
	q42.AddOption("", -1)
	q42.AddOption("", -1)
	q42.AddOption("", -1)
	
	Question q43("?")
	q43.AddOption("", -1)
	q43.AddOption("", -1)
	q43.AddOption("", -1)
	q43.AddOption("", -1)
	
	Question q44("?")
	q44.AddOption("", -1)
	q44.AddOption("", -1)
	q44.AddOption("", -1)
	q44.AddOption("", -1)
	
	Question q45("?")
	q45.AddOption("", -1)
	q45.AddOption("", -1)
	q45.AddOption("", -1)
	q45.AddOption("", -1)
	
	Question q46("?")
	q46.AddOption("", -1)
	q46.AddOption("", -1)
	q46.AddOption("", -1)
	q46.AddOption("", -1)
	
	Question q47("?")
	q47.AddOption("", -1)
	q47.AddOption("", -1)
	q47.AddOption("", -1)
	q47.AddOption("", -1)
	
	Question q48("?")
	q48.AddOption("", -1)
	q48.AddOption("", -1)
	q48.AddOption("", -1)
	q48.AddOption("", -1)
	
	Question q49("?")
	q49.AddOption("", -1)
	q49.AddOption("", -1)
	q49.AddOption("", -1)
	q49.AddOption("", -1)
	
	Question q50("?")
	q50.AddOption("", -1)
	q50.AddOption("", -1)
	q50.AddOption("", -1)
	q50.AddOption("", -1)
	
	Question q51("?")
	q51.AddOption("", -1)
	q51.AddOption("", -1)
	q51.AddOption("", -1)
	q51.AddOption("", -1)
	
	Question q52("?")
	q52.AddOption("", -1)
	q52.AddOption("", -1)
	q52.AddOption("", -1)
	q52.AddOption("", -1)
	
	Question q53("?")
	q53.AddOption("", -1)
	q53.AddOption("", -1)
	q53.AddOption("", -1)
	q53.AddOption("", -1)
	
	Question q54("?")
	q54.AddOption("", -1)
	q54.AddOption("", -1)
	q54.AddOption("", -1)
	q54.AddOption("", -1)
	
	Question q55("?")
	q55.AddOption("", -1)
	q55.AddOption("", -1)
	q55.AddOption("", -1)
	q55.AddOption("", -1)
	
	Question q56("?")
	q56.AddOption("", -1)
	q56.AddOption("", -1)
	q56.AddOption("", -1)
	q56.AddOption("", -1)
	
	Question q57("?")
	q57.AddOption("", -1)
	q57.AddOption("", -1)
	q57.AddOption("", -1)
	q57.AddOption("", -1)
	
	Question q58("?")
	q58.AddOption("", -1)
	q58.AddOption("", -1)
	q58.AddOption("", -1)
	q58.AddOption("", -1)
	
	Question q59("?")
	q59.AddOption("", -1)
	q59.AddOption("", -1)
	q59.AddOption("", -1)
	q59.AddOption("", -1)
	
	Question q60("?")
	q60.AddOption("", -1)
	q60.AddOption("", -1)
	q60.AddOption("", -1)
	q60.AddOption("", -1)
	
	Question q61("?")
	q61.AddOption("", -1)
	q61.AddOption("", -1)
	q61.AddOption("", -1)
	q61.AddOption("", -1)
	
	Question q62("?")
	q62.AddOption("", -1)
	q62.AddOption("", -1)
	q62.AddOption("", -1)
	q62.AddOption("", -1)
	
	Question q63("?")
	q63.AddOption("", -1)
	q63.AddOption("", -1)
	q63.AddOption("", -1)
	q63.AddOption("", -1)
	
	Question q64("?")
	q64.AddOption("", -1)
	q64.AddOption("", -1)
	q64.AddOption("", -1)
	q64.AddOption("", -1)
	
	Question q65("?")
	q65.AddOption("", -1)
	q65.AddOption("", -1)
	q65.AddOption("", -1)
	q65.AddOption("", -1)
	
	Question q66("?")
	q66.AddOption("", -1)
	q66.AddOption("", -1)
	q66.AddOption("", -1)
	q66.AddOption("", -1)
	
	Question q67("?")
	q67.AddOption("", -1)
	q67.AddOption("", -1)
	q67.AddOption("", -1)
	q67.AddOption("", -1)
	
	Question q68("?")
	q68.AddOption("", -1)
	q68.AddOption("", -1)
	q68.AddOption("", -1)
	q68.AddOption("", -1)
	
	Question q69("?")
	q69.AddOption("", -1)
	q69.AddOption("", -1)
	q69.AddOption("", -1)
	q69.AddOption("", -1)
	
	Question q70("?")
	q70.AddOption("", -1)
	q70.AddOption("", -1)
	q70.AddOption("", -1)
	q70.AddOption("", -1)
	
	Question q71("?")
	q71.AddOption("", -1)
	q71.AddOption("", -1)
	q71.AddOption("", -1)
	q71.AddOption("", -1)
	
	Question q72("?")
	q72.AddOption("", -1)
	q72.AddOption("", -1)
	q72.AddOption("", -1)
	q72.AddOption("", -1)
	
	Question q73("?")
	q73.AddOption("", -1)
	q73.AddOption("", -1)
	q73.AddOption("", -1)
	q73.AddOption("", -1)
	
	Question q74("?")
	q74.AddOption("", -1)
	q74.AddOption("", -1)
	q74.AddOption("", -1)
	q74.AddOption("", -1)
	
	Question q75("?")
	q75.AddOption("", -1)
	q75.AddOption("", -1)
	q75.AddOption("", -1)
	q75.AddOption("", -1)
	
	Question q76("?")
	q76.AddOption("", -1)
	q76.AddOption("", -1)
	q76.AddOption("", -1)
	q76.AddOption("", -1)
	
	Question q77("?")
	q77.AddOption("", -1)
	q77.AddOption("", -1)
	q77.AddOption("", -1)
	q77.AddOption("", -1)
	
	Question q78("?")
	q78.AddOption("", -1)
	q78.AddOption("", -1)
	q78.AddOption("", -1)
	q78.AddOption("", -1)
	
	Question q79("?")
	q79.AddOption("", -1)
	q79.AddOption("", -1)
	q79.AddOption("", -1)
	q79.AddOption("", -1)
	
	Question q80("?")
	q80.AddOption("", -1)
	q80.AddOption("", -1)
	q80.AddOption("", -1)
	q80.AddOption("", -1)
	
	Question q81("?")
	q81.AddOption("", -1)
	q81.AddOption("", -1)
	q81.AddOption("", -1)
	q81.AddOption("", -1)
	
	Question q82("?")
	q82.AddOption("", -1)
	q82.AddOption("", -1)
	q82.AddOption("", -1)
	q82.AddOption("", -1)
	
	Question q83("?")
	q83.AddOption("", -1)
	q83.AddOption("", -1)
	q83.AddOption("", -1)
	q83.AddOption("", -1)
	
	Question q84("?")
	q84.AddOption("", -1)
	q84.AddOption("", -1)
	q84.AddOption("", -1)
	q84.AddOption("", -1)
	
	Question q85("?")
	q85.AddOption("", -1)
	q85.AddOption("", -1)
	q85.AddOption("", -1)
	q85.AddOption("", -1)
	
	Question q86("?")
	q86.AddOption("", -1)
	q86.AddOption("", -1)
	q86.AddOption("", -1)
	q86.AddOption("", -1)
	
	Question q87("?")
	q87.AddOption("", -1)
	q87.AddOption("", -1)
	q87.AddOption("", -1)
	q87.AddOption("", -1)
	
	Question q88("?")
	q88.AddOption("", -1)
	q88.AddOption("", -1)
	q88.AddOption("", -1)
	q88.AddOption("", -1)
	
	Question q89("?")
	q89.AddOption("", -1)
	q89.AddOption("", -1)
	q89.AddOption("", -1)
	q89.AddOption("", -1)
	
	Question q90("?")
	q90.AddOption("", -1)
	q90.AddOption("", -1)
	q90.AddOption("", -1)
	q90.AddOption("", -1)
	
	Question q91("?")
	q91.AddOption("", -1)
	q91.AddOption("", -1)
	q91.AddOption("", -1)
	q91.AddOption("", -1)
	
	Question q92("?")
	q92.AddOption("", -1)
	q92.AddOption("", -1)
	q92.AddOption("", -1)
	q92.AddOption("", -1)
	
	Question q93("?")
	q93.AddOption("", -1)
	q93.AddOption("", -1)
	q93.AddOption("", -1)
	q93.AddOption("", -1)
	
	Question q94("?")
	q94.AddOption("", -1)
	q94.AddOption("", -1)
	q94.AddOption("", -1)
	q94.AddOption("", -1)
	
	Question q95("?")
	q95.AddOption("", -1)
	q95.AddOption("", -1)
	q95.AddOption("", -1)
	q95.AddOption("", -1)
	
	Question q96("?")
	q96.AddOption("", -1)
	q96.AddOption("", -1)
	q96.AddOption("", -1)
	q96.AddOption("", -1)
	
	Question q97("?")
	q97.AddOption("", -1)
	q97.AddOption("", -1)
	q97.AddOption("", -1)
	q97.AddOption("", -1)
	
	Question q98("?")
	q98.AddOption("", -1)
	q98.AddOption("", -1)
	q98.AddOption("", -1)
	q98.AddOption("", -1)
	
	Question q99("?")
	q99.AddOption("", -1)
	q99.AddOption("", -1)
	q99.AddOption("", -1)
	q99.AddOption("", -1)
	
	Question q100("?")
	q100.AddOption("", -1)
	q100.AddOption("", -1)
	q100.AddOption("", -1)
	q100.AddOption("", -1)
	
	Question q101("?")
	q101.AddOption("", -1)
	q101.AddOption("", -1)
	q101.AddOption("", -1)
	q101.AddOption("", -1)
	
	Question q102("?")
	q102.AddOption("", -1)
	q102.AddOption("", -1)
	q102.AddOption("", -1)
	q102.AddOption("", -1)
	
	Question q103("?")
	q103.AddOption("", -1)
	q103.AddOption("", -1)
	q103.AddOption("", -1)
	q103.AddOption("", -1)
	
	Question q104("?")
	q104.AddOption("", -1)
	q104.AddOption("", -1)
	q104.AddOption("", -1)
	q104.AddOption("", -1)
	
	Question q105("?")
	q105.AddOption("", -1)
	q105.AddOption("", -1)
	q105.AddOption("", -1)
	q105.AddOption("", -1)
	
	Question q106("?")
	q106.AddOption("", -1)
	q106.AddOption("", -1)
	q106.AddOption("", -1)
	q106.AddOption("", -1)
	
	Question q107("?")
	q107.AddOption("", -1)
	q107.AddOption("", -1)
	q107.AddOption("", -1)
	q107.AddOption("", -1)
	
	Question q108("?")
	q108.AddOption("", -1)
	q108.AddOption("", -1)
	q108.AddOption("", -1)
	q108.AddOption("", -1)
	
	Question q109("?")
	q109.AddOption("", -1)
	q109.AddOption("", -1)
	q109.AddOption("", -1)
	q109.AddOption("", -1)
	
	Question q110("?")
	q110.AddOption("", -1)
	q110.AddOption("", -1)
	q110.AddOption("", -1)
	q110.AddOption("", -1)
	
	Question q111("?")
	q111.AddOption("", -1)
	q111.AddOption("", -1)
	q111.AddOption("", -1)
	q111.AddOption("", -1)
	
	Question q112("?")
	q112.AddOption("", -1)
	q112.AddOption("", -1)
	q112.AddOption("", -1)
	q112.AddOption("", -1)
	
	Question q113("?")
	q113.AddOption("", -1)
	q113.AddOption("", -1)
	q113.AddOption("", -1)
	q113.AddOption("", -1)
	
	Question q114("?")
	q114.AddOption("", -1)
	q114.AddOption("", -1)
	q114.AddOption("", -1)
	q114.AddOption("", -1)
	
	Question q115("?")
	q115.AddOption("", -1)
	q115.AddOption("", -1)
	q115.AddOption("", -1)
	q115.AddOption("", -1)
	
	Question q116("?")
	q116.AddOption("", -1)
	q116.AddOption("", -1)
	q116.AddOption("", -1)
	q116.AddOption("", -1)
	
	Question q117("?")
	q117.AddOption("", -1)
	q117.AddOption("", -1)
	q117.AddOption("", -1)
	q117.AddOption("", -1)
	
	Question q118("?")
	q118.AddOption("", -1)
	q118.AddOption("", -1)
	q118.AddOption("", -1)
	q118.AddOption("", -1)
	
	Question q119("?")
	q119.AddOption("", -1)
	q119.AddOption("", -1)
	q119.AddOption("", -1)
	q119.AddOption("", -1)
	
	Question q120("?")
	q120.AddOption("", -1)
	q120.AddOption("", -1)
	q120.AddOption("", -1)
	q120.AddOption("", -1)
	
	Question q121("?")
	q121.AddOption("", -1)
	q121.AddOption("", -1)
	q121.AddOption("", -1)
	q121.AddOption("", -1)
	
	Question q122("?")
	q122.AddOption("", -1)
	q122.AddOption("", -1)
	q122.AddOption("", -1)
	q122.AddOption("", -1)
	
	Question q123("?")
	q123.AddOption("", -1)
	q123.AddOption("", -1)
	q123.AddOption("", -1)
	q123.AddOption("", -1)
	
	Question q124("?")
	q124.AddOption("", -1)
	q124.AddOption("", -1)
	q124.AddOption("", -1)
	q124.AddOption("", -1)
	
	Question q125("?")
	q125.AddOption("", -1)
	q125.AddOption("", -1)
	q125.AddOption("", -1)
	q125.AddOption("", -1)
	
	Question q126("?")
	q126.AddOption("", -1)
	q126.AddOption("", -1)
	q126.AddOption("", -1)
	q126.AddOption("", -1)
	
	Question q127("?")
	q127.AddOption("", -1)
	q127.AddOption("", -1)
	q127.AddOption("", -1)
	q127.AddOption("", -1)
	
	Question q128("?")
	q128.AddOption("", -1)
	q128.AddOption("", -1)
	q128.AddOption("", -1)
	q128.AddOption("", -1)
	
	Question q129("?")
	q129.AddOption("", -1)
	q129.AddOption("", -1)
	q129.AddOption("", -1)
	q129.AddOption("", -1)
	
	Question q130("?")
	q130.AddOption("", -1)
	q130.AddOption("", -1)
	q130.AddOption("", -1)
	q130.AddOption("", -1)
	
	Question q131("?")
	q131.AddOption("", -1)
	q131.AddOption("", -1)
	q131.AddOption("", -1)
	q131.AddOption("", -1)
	
	Question q132("?")
	q132.AddOption("", -1)
	q132.AddOption("", -1)
	q132.AddOption("", -1)
	q132.AddOption("", -1)
	
	Question q133("?")
	q133.AddOption("", -1)
	q133.AddOption("", -1)
	q133.AddOption("", -1)
	q133.AddOption("", -1)
	
	Question q134("?")
	q134.AddOption("", -1)
	q134.AddOption("", -1)
	q134.AddOption("", -1)
	q134.AddOption("", -1)
	
	Question q135("?")
	q135.AddOption("", -1)
	q135.AddOption("", -1)
	q135.AddOption("", -1)
	q135.AddOption("", -1)
	
	Question q136("?")
	q136.AddOption("", -1)
	q136.AddOption("", -1)
	q136.AddOption("", -1)
	q136.AddOption("", -1)
	
	Question q137("?")
	q137.AddOption("", -1)
	q137.AddOption("", -1)
	q137.AddOption("", -1)
	q137.AddOption("", -1)
	
	Question q138("?")
	q138.AddOption("", -1)
	q138.AddOption("", -1)
	q138.AddOption("", -1)
	q138.AddOption("", -1)
	
	Question q139("?")
	q139.AddOption("", -1)
	q139.AddOption("", -1)
	q139.AddOption("", -1)
	q139.AddOption("", -1)
	
	Question q140("?")
	q140.AddOption("", -1)
	q140.AddOption("", -1)
	q140.AddOption("", -1)
	q140.AddOption("", -1)
	
	Question q141("?")
	q141.AddOption("", -1)
	q141.AddOption("", -1)
	q141.AddOption("", -1)
	q141.AddOption("", -1)
	
	Question q142("?")
	q142.AddOption("", -1)
	q142.AddOption("", -1)
	q142.AddOption("", -1)
	q142.AddOption("", -1)
	
	Question q143("?")
	q143.AddOption("", -1)
	q143.AddOption("", -1)
	q143.AddOption("", -1)
	q143.AddOption("", -1)
	
	Question q144("?")
	q144.AddOption("", -1)
	q144.AddOption("", -1)
	q144.AddOption("", -1)
	q144.AddOption("", -1)
	
	Question q145("?")
	q145.AddOption("", -1)
	q145.AddOption("", -1)
	q145.AddOption("", -1)
	q145.AddOption("", -1)
	
	Question q146("?")
	q146.AddOption("", -1)
	q146.AddOption("", -1)
	q146.AddOption("", -1)
	q146.AddOption("", -1)
	
	Question q147("?")
	q147.AddOption("", -1)
	q147.AddOption("", -1)
	q147.AddOption("", -1)
	q147.AddOption("", -1)
	
	Question q148("?")
	q148.AddOption("", -1)
	q148.AddOption("", -1)
	q148.AddOption("", -1)
	q148.AddOption("", -1)
	
	Question q149("?")
	q149.AddOption("", -1)
	q149.AddOption("", -1)
	q149.AddOption("", -1)
	q149.AddOption("", -1)
	
	Question q150("?")
	q150.AddOption("", -1)
	q150.AddOption("", -1)
	q150.AddOption("", -1)
	q150.AddOption("", -1)
	
	/*
	Question q0("?");
	q0.AddOption("", -1);
	q0.AddOption("", -1);
	q0.AddOption("", -1);
	q0.AddOption("", -1);
	exam.push_back(q0);
	*/

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i < questionsCount; ++i)
		std::swap(exam[Randomize(exam.size())], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i < exam.size(); ++i)
	{
		if (i == questionsCount)
		{
			std::cout << "Sekciq sus sgresheni vuprosi\nnatisnete nqkoy buton\n";
			std::cin >> useless;
			system("CLS");
		}
		std::cout << 1 + i << '/' << exam.size() << '\n';
		exam[i].AskQuestion();
		if (exam[i].AnswerQuestion() != 1 && !flag)
			exam.push_back(exam[i]);
		std::cin >> useless;
		system("CLS");
	}
	std::cout << "Congratulations for reaching the end!\nYour score is: " << counter << '/' << exam.size();
	std::cin >> useless;
	return 0;
}
