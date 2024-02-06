//
// Created by alkaratus on 04.01.24.
//
#include <vector>
#include "Utilities.h"
#include "Question_Round_4.h"
#include "Question_Round_5.h"
#include "Hard_Coded_Question_Provider/Hard_Coded_Question_Provider.h"


const std::vector<Question_Round_1>round_1_questions={
        Question_Round_1("Czym się gasi płonącą benzynę?", "Piaskiem", "Wodą", 0),
        Question_Round_1("Co służy delfinom i nietoperzom do echolokacji?", "Infradźwięki", "Ultradźwięki", 1),
        Question_Round_1("Jak nazywa się przyrząd do pomiaru wilgotności?", "Manometr", "Higrometr", 1),
        Question_Round_1("Która konstytucja była pierwszą w Polsce po odzyskaniu niepodległości?", "Marcowa", "Kwietniowa", 0),
        Question_Round_1("Jak brzmi nazwisko \"dynastii\" polskich malarzy-batalistów?", "Kossak", "Fałat", 0),
        Question_Round_1("W którym z tych seriali występuje Lisa Kudrow?", "Rodzina Adamsów", "Przyjaciele", 1),
        Question_Round_1("W jakiej dyscyplinie sportu zawodnicy pocierają lód szczotkami?", "W bandy", "W curlingu", 1),
        Question_Round_1("O jakie terytorium spierają się Argentyna i Wielka Brytania", "Antyle", "Falklandy", 1),
        Question_Round_1("Co je zimorodek?", "Owoce", "Ryby", 1),
        Question_Round_1("W którym wieku toczyła się wojna trzydziestoletnia?", "XVII", "XVI", 0),
        Question_Round_1("Jakie drzewa dominują w borze?", "Liściaste", "Iglaste", 1),
        Question_Round_1("Kto łatwo nawiązuje kontakty z innymi ludźmi?", "Introwertyk", "Ekstrawertyk", 1),
        Question_Round_1("Jaki proces polega na bezpośrednim przejściu substancji ze stanu stałego w gazowy?", "Sublimacja", "Resublimacja", 0),
        Question_Round_1("Po kłótni z którym malarzem, Van Gogh odciął ucho?", "Z Gauguinem", "Z Monetem", 0),
        Question_Round_1("Piejący kogut to element którego programu TVP?", "Teleranka", "Wieczorynki", 0),
        Question_Round_1("Kleopatra poniosła śmierć w wyniku?", "Ukąszenia przez węża", "Przebicia mieczem", 0),
        Question_Round_1("75% masy słońca stanowi?", "Wodór", "Hel", 0),
        Question_Round_1("Tatrzański Park Narodowy leży w województwie...", "Podkarpackim", "Małopolskim", 1),
        Question_Round_1("Co borowik szlachetny ma od spodu kapelusza?", "Blaszki", "Rurki", 1),
        Question_Round_1("Indiański namiot to...", "Tipi", "Jurta", 0),
        Question_Round_1("Która Lalka teatralna jest poruszana przy użyciu drutów", "Marionetka", "Pacynka", 0),
        Question_Round_1("Gdzie leży kraj basków?", "We Francji", "W Hiszpanii", 1),
        Question_Round_1("Jak nazywa się wierny sługa Horeszków z \"Pana Tadeusza\"?", "Gerwazy", "Protazy", 0),
        Question_Round_1("Która msza odbywa się wczesnym rankiem w niedzielę wielkanocną?", "Rezurekcja", "Pasterka", 0),
        Question_Round_1("Roślina chroniona charakterystyczna dla Tatr to?", "Szarotka", "Mikołajek", 0),
        Question_Round_1("Kto był bratem Kaina?", "Adam", "Abel", 1),
        Question_Round_1("Który element żaglowca jest drzewcem poziomym?", "Maszt", "Reja", 1),
        Question_Round_1("Kwasy Omega-3 to jakie tłuszcze?", "Nienasycone", "Nasycone", 0)
};

const std::vector<Question_Round_2>round_2_questions={
        Question_Round_2("Który krzyż w brytyjskiej fladze symbolizuje Szkocję", "Św. Patryka", "Św. Andrzeja", "Św. Jerzego", 1),
        Question_Round_2("Kiedy Żydzi zaczynają święcić szabat?", "W piątek", "W sobotę", "W niedzielę", 0),
        Question_Round_2("Kim jest znany z kreskówek Pędziwiatr?", "Łosiem", "Strusiem", "Gepardem", 1),
        Question_Round_2("Na którą sylabę od końca pada akcent większości polskich wyrazów?", "Na pierwszą", "Na drugą", "Na trzecią", 1),
        Question_Round_2("Z którego kraju pochodzi sos pesto?", "Z Portugalii", "Z Włoch", "Z Hiszpanii", 1),
        Question_Round_2("Jakiej barwy jest tło flagi Finlandii?", "Czerwonej", "Niebieskiej", "Białej", 2),
        Question_Round_2("Jak nazywa się górski gryzoń wydający charakterystyczny gwizd?", "Bóbr", "Świstak", "Kawia", 1),
        Question_Round_2("W którym mieście znajduje się teatr operowy La Scala?", "Rzym", "Neapol", "Mediolan", 2),
        Question_Round_2("Jak się nazywa kompozytor piosenki \"Ostatnia Niedziela\"?", "Ryszard Poznakowski", "Mieczysław Fogg", "Jerzy Petersburski", 2),
        Question_Round_2("Ile zębów trzonowych posiada człowiek?", "4", "8", "12", 2),
        Question_Round_2("Kto wyrabia naczynia z drewnianych klepek?", "Rymarz", "Kaletnik", "Bednarz", 2),
        Question_Round_2("Co ogłasza capstrzyk?", "Pobudkę", "Obiad", "Koniec zajęć", 2),
        Question_Round_2("Gdzie leży Batumi?", "W Armenii", "W Gruzji", "Na Ukrainie", 1),
        Question_Round_2("Która choroba zakaźna to dyzenteria?", "Grypa", "Czerwonka", "Tyfus", 1),
        Question_Round_2("W którym filmie Daniel Olbrychski wcielił się w postać Wiktora Rubena?", "W \"Brzezinie\"", "W \"Pannach z Wilka\"", "W \"Ziemi Obiecanej\"", 1),
        Question_Round_2("Co oznacza przekreślony trójkąt na metce ubrania?", "Nie wirować", "Nie prać chemicznie", "Nie chlorować", 2),
        Question_Round_2("Gdzie odbywa się festiwal filmowy, na którym nagrodą jest Złota Palma?", "W Wenecji", "W Monte Carlo", "W Cannes", 2),
        Question_Round_2("Marsylianka to hymn?", "Francji", "Niemiec", "Holandii", 0),
        Question_Round_2("Ile razy odbyły się zbrojne wyprawy krzyżowe?", "4", "6", "7", 2),
        Question_Round_2("Kwas Askorbinowy to która witamina?", "A", "B", "C", 2),
        Question_Round_2("Jak się wabił pierwszy pies w kosmosie?", "Łajka", "Biełka", "Striełka", 0),
        Question_Round_2("Które ciało niebiskie świeci światłem emitowanym?", "Gwiazda", "Planeta", "Księżyc", 0),
        Question_Round_2("Sandro Botticelli namalował \"Narodziny...", "Wenus", "Hery", "Ateny", 0),
        Question_Round_2("Rihanna pochodzi z wyspy...", "Barbados", "Jamajki", "Kuby", 0),
        Question_Round_2("Których krwinek w ludzkim organizmie jest najwięcej?", "Erytrocytów", "Leukocytów", "Trombocytów", 0),
        Question_Round_2("Adolphe Sax, wynalazca saksofonu to?", "Belg", "Francuz", "Anglik", 0),
        Question_Round_2("Symbol natężenia prądu elektrycznego to?", "U", "I", "R", 1),
        Question_Round_2("Który instrument jest strunowy?", "Klarnet", "Fagot", "Lutnia", 2),
        Question_Round_2("Który styl artystyczny jest najmłodszy?", "Barok", "Renesans", "Gotyk", 0),
        Question_Round_2("Które zwierze jest największe?", "Łoś", "Jeleń", "Daniel", 0),
        Question_Round_2("Który symbol oznacza Potas?", "F", "K", "S", 1),
        Question_Round_2("Który ssak ma ogon pokryty łuskami?", "Bóbr", "Chomik", "Borsuk", 0),
        Question_Round_2("W którym wieku koronowano pierwszego króla polski?", "X", "XI", "XII", 1),
        Question_Round_2("Którego koloru nie ma we fladze Belgii?", "Żółty", "Czerwony", "Niebieski", 2),
        Question_Round_2("Które owoce nie rosną na palmach?", "Daktyle", "Banany", "Kokosy", 1),
        Question_Round_2("Która z witamin powstaje pod wpływem słońca?", "C", "D", "E", 1),
        Question_Round_2("Jakim głosem śpiewał Jan Kiepura?", "Tenorem", "Barytonem", "Basem", 0),
        Question_Round_2("Piracka bandera jest inaczej nazywana Wesołym...", "Dickiem", "Johnem", "Rogerem", 2),
        Question_Round_2("Akcja \"Ojca Mateusza\" ma miejsce w?", "Sandomierzu", "Kielcach", "Pinczowie", 0),
        Question_Round_2("Który z napojów nie zawiera kofeiny?", "Kawa", "Herbata", "Roibos", 2),
        Question_Round_2("Samica wilka to?", "Wadera", "Basiora", "Klępa", 0),
        Question_Round_2("Które z miast ma w herbie koronę?", "Bydgoszcz", "Poznań", "Zielona Góra", 1),
        Question_Round_2("Z czego Wit Stworz zrobił ołtarz w kościele Mariackim?", "Z Drewna", "Ze Złota", "Z Marmuru", 0),
        Question_Round_2("W którym roku powstał przebój Beyonce \"Single Ladies\"?", "2007", "2008", "2009", 1),
        Question_Round_2("Na czym rosną owoce awokado?", "Na drzewach", "Na krzewach", "Na pnączach", 0),
        Question_Round_2("Który malarz jest ojcem impresjonizmu?", "Renoir", "Monet", "Manet", 1),
        Question_Round_2("Z ilu płatów składają się płuca człowieka?", "3", "4", "5", 2),
        Question_Round_2("Który kraj ma najwięcej tytułów mistrza w piłce nożnej?", "Niemcy", "Brazylia", "Włochy", 1),
        Question_Round_2("Apostołami było 2...", "Jakubów", "Filipów", "Janów", 0),
        Question_Round_2("W którym mieście toczy się akcja \"Lalki\" B. Prusa", "W Krakowie", "W Warszawie", "We Lwowie", 1),
        Question_Round_2("Ile sekund trwa jeden interwał treningu tabata", "10", "20", "30", 2),
        Question_Round_2("Która z monet ma największą średnicę", "5 gr", "10 gr", "20 gr", 0),
        Question_Round_2("Puchar Stanleya to najważniejszy turniej...", "Hokeja", "Koszykówki", "Rugby", 0),
        Question_Round_2("Który ser jest podstawą pizzy", "Gorgonzola", "Mozzarella", "Parmezan", 1),
        Question_Round_2("SMS to skrót od Short Message...", "Send", "Service", "System", 1),
        Question_Round_2("Gdzie kobiety zyskały najwcześniej prawa wyborcze", "We Francji", "W Polsce", "W Szwajcarii", 1),
        Question_Round_2("Który z piłkarzy ma \"7\" na koszulce", "Antoine Griezmann", "Karim Benzema", "Luiz Suarez", 0),
        Question_Round_2("Który kraj jako pierwszy był gospodarzem 1 mundiali", "Niemcy", "Brazylia", "Meksyk", 2)
};

const std::vector<Question_Round_3>round_3_questions={
        Question_Round_3("Który z pierwiastków jest oznaczony symbolem C?", "Cynk", "Potas", "Węgiel", "Cyna", 2),
        Question_Round_3("Kto dosiadał Rosynanta?", "Król Artur", "Don Kichot", "Parsifal", "Sancho Pansa", 1),
        Question_Round_3("Kogo diabli nie wezmą?", "Swego", "Złego", "Świętego", "Głupiego", 1),
        Question_Round_3("Kto w 1989 roku zaproponował politykę \"grubej kreski\"?", "Wojciech Jaruzelski", "Leszek Balcerowicz", "Lech Wałęsa", "Tadeusz Mazowiecki", 3),
        Question_Round_3("Kto stworzył postać pana Cogito?", "Czesław Miłosz", "Sławomir Mrożek", "Zbigniew Herbert", "Wisława Szymborska", 2),
        Question_Round_3("Kto powiedział \"Veni, vidi, deus vicit\"?", "Juliusz Cezar", "Karol Wielki", "Jan III Sobieski", "Filip II", 2),
        Question_Round_3("Kto organizował słynne obiady czwartkowe?", "Ignacy Krasicki", "król Stanisław August", "Adam Naruszewicz", "Józef Poniatowski", 1),
        Question_Round_3("Który pies kojarzy się ze śmiertelną nudą?", "Ratlerek", "Pekińczyk", "Jamnik", "Mops", 3),
        Question_Round_3("Ile okrążeń liczy wyścig żużlowy?", "2", "3", "4", "5", 2),
        Question_Round_3("Truskawki ze śmietaną są przysmakiem którego z tenisowych turniejów?", "Australian Open", "Roland Garros", "Wimbledon", "US Open", 2),
        Question_Round_3("Gdzie możemy obejrzeć większość budynków stworzonych przez Antoniego Gaudiego?", "W Barcelonie", "W Madrycie", "W Sewilli", "W Walencji", 0),
        Question_Round_3("W którym roku Michaił Gorbaczow otrzymał pokojową Nagrodę Nobla?", "1988", "1989", "1990", "1991", 2)

};

const std::vector<Question_Round_4>round_4_questions={
        Question_Round_4("Co układają osoby biegłe w sztuce ikebany?", "Pasjanse", "Wiersze", "Krzyżówki", "Horoskopy", "Kwiaty", 4),
        Question_Round_4("Która rasa psów, nie zalicza się do myśliwskich?", "Pinczer", "Jamnik", "Foksterier", "Spaniel", "Wyżeł", 0),
        Question_Round_4("Czego uczy Adam Miauczyński, główny bohater filmu \"dzień świra\"?", "Chemii", "Fizyki", "Polskiego", "Rosyjskiego", "Matematyki", 2),
        Question_Round_4("Do kogo Francesco Petrarca adresował swoje sonety?", "Do Belatrix", "Do Izoldy", "Do Laury", "Do Julii", "Do Rebeci", 2),
        Question_Round_4("Samcem którego owada jest truteń?", "Muchy", "Osy", "Pszczoły", "Mszycy", "Modliszki", 2),
        Question_Round_4("Który polski park narodowy jest największy?", "Białowieski", "Słowiński", "Kampinoski", "Tatrzański", "Biebrzański", 4),
        Question_Round_4("Który rożek jest instrumentem orkiestry symfonicznej?", "Francuski", "Angielski", "Niemiecki", "Polski", "Włoski", 1),
        Question_Round_4("Który piosenkarz zespołu \"Backstreet Boys\" jest najmłodszy?", "Howie Dorough", "Kevin Richardson", "AJ McLean", "Nick Carter", "Brian Littrell", 3),
        Question_Round_4("Lęk przed wężami to?", "Ochofobia", "Oenofobia", "Ofidiofobia", "Ombrofobia", "Ornitofobia", 2),
        Question_Round_4("Który z prezydentów RP, składając przysięgę, był najmłodszy?", "Lech Wałęsa", "Aleksander Kwaśniewski", "Lech Kaczyński", "Bronisław Komorowski", "Andrzej Duda", 1),
        Question_Round_4("Który tatrzański szczyt jest najwyższy?", "Durny Szczyt", "Lawinowy Szczyt", "Lodowa Kopa", "Lodowy Szczyt", "Łomnica", 4),
        Question_Round_4("\"Vamos al mundial\" Jennifer Peny to hymn mistrzostw świata FIFA...", "1990", "1994", "1998", "2002", "2006", 3)
};

const std::vector<Question_Round_5>round_5_questions={
        Question_Round_5("Jaki związek chemiczny stanowi 95% atmosfery Marsa? Podaj wzór chemiczny", "CO2"),
        Question_Round_5("Który skandynawski kraj nie przystąpił do UE?", "NORWEGIA"),
        Question_Round_5("Jak nazywa się nazywa grecka bogini łowów?", "ARTEMIDA"),
        Question_Round_5("Jaki jest kraj pochodzenia marki samochodów Volvo?", "SZWECJA"),
        Question_Round_5("Który kraj w 1950 został&sbquo; zaanektowany przez Chiny", "TYBET"),
        Question_Round_5("Jaka jest nazwa albumu, zespołu \"Linkin Park\" w którym zawarta jest piosenka \"Numb\"", "METEORA"),
        Question_Round_5("Jakim symbolem oznaczamy liczbę masową?", "A"),
        Question_Round_5("Dokończ przysłowie \"Woda czyści żołądek a piwo...\"", "KIESZEŃ"),
        Question_Round_5("Jak brzmi imię bogini której Perseusz ofiarował głowę Meduzy", "ATENA"),
        Question_Round_5("Jak ogólnie nazywamy protony i neutrony z których składa się jądro atomowe? ", "NUKLEONY"),
        Question_Round_5("Ile razy reprezentacja Polski zagrała na mistrzostwach świata w piłce nożnej? Podaj liczbę", "9")
};

Question_Round_1 Hard_Coded_Question_Provider::get_round_1_question_data(const unsigned int index) {
    return round_1_questions[index];
}

Question_Round_2 Hard_Coded_Question_Provider::get_round_2_question_data(const unsigned int index) {
    return round_2_questions[index];
}

Question_Round_3 Hard_Coded_Question_Provider::get_round_3_question_data(const unsigned int index) {
    return round_3_questions[index];
}

Question_Round_4 Hard_Coded_Question_Provider::get_round_4_question_data(const unsigned int index) {
    return round_4_questions[index];
}

Question_Round_5 Hard_Coded_Question_Provider::get_round_5_question_data(const unsigned int index) {
    return round_5_questions[index];
}

Hard_Coded_Question_Provider::Hard_Coded_Question_Provider() {
    set_round_1_questions_IDs(generate_random_unique_list(0,round_1_questions.size()-1,ROUND_1_QUESTIONS_NUMBER));
    set_round_2_questions_IDs(generate_random_unique_list(0,round_2_questions.size()-1,ROUND_2_QUESTIONS_NUMBER));
    set_round_3_questions_IDs(generate_random_unique_list(0,round_3_questions.size()-1,ROUND_3_QUESTIONS_NUMBER));
    set_round_4_questions_IDs(generate_random_unique_list(0,round_4_questions.size()-1,ROUND_4_QUESTIONS_NUMBER));
    set_round_5_questions_IDs(generate_random_unique_list(0,round_5_questions.size()-1,ROUND_5_QUESTIONS_NUMBER));
}
