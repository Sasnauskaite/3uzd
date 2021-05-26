template <class T>
void PrintRez(T& S)
{
	std::ofstream fr(outFile);
	fr <<std::setw(20) << v << std::setw(20) << p << std::setw(15) << vidd << std::setw(15) <<
	medd << endl;
	for(int i=0; i<70; i++)
	{
		fr << line;
	}
	fr << endl;
	string eil;
	for (auto &a : S)
	{
		fr << std::setw(20) << a.get_name() << std::setw(20) << a.get_lastname() << std::setw(20) << std::setprecision(3) << a.get_avg() << 
		std::setw(20) << std::setprecision(3) << a.get_med() << endl;
	}
	fr.close();
}
template <class T>
void PrintBothAvg(T& S)
{
	std::ofstream out1("Galvotukai.txt");
	std::ofstream out2("Vargsiukai.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < studs; i++)
	{
		if (S[i].get_skolaAvg() == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_avg() << endl;
		}
		else if (S[i].get_skolaAvg() == 1)
		{
			out2 <<std::left<< std::setw(20) <<S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
			S[i].get_avg() << endl;
		}
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintBothMed(T& S)
{
	std::ofstream out1("Galvotukai.txt");
	std::ofstream out2("Vargsiukai.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < studs; i++)
	{
		if (S[i].get_skolaMed() == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_med() << endl;
		}
		else if (S[i].get_skolaMed() == 1)
		{
			out2 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_med() << endl;
		}
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintVectorAvg(T& S)
{
	std::ofstream out1("GalvotukaiVector0.txt");
	std::ofstream out2("VargsiukaiVector0.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < studs; i++)
	{
		if (S[i].get_skolaAvg() == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_avg() << endl;
		}
		else if (S[i].get_skolaAvg() == 1)
		{
			out2 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_avg() << endl;
		}
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintVectorMed(T& S)
{
	std::ofstream out1("GalvotukaiVector0.txt");
	std::ofstream out2("VargsiukaiVector0.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < studs; i++)
	{
		if (S[i].get_skolaMed() == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_med() << endl;
		}
		else if (S[i].get_skolaMed() == 1)
		{
			out2 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_med() << endl;
		}
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintDequeAvg(T& S)
{
	std::ofstream out1("GalvotukaiDeque0.txt");
	std::ofstream out2("VargsiukaiDeque0.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < studs; i++)
	{
		if (S[i].get_skolaAvg() == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_avg() << endl;
		}
		else if (S[i].get_skolaAvg() == 1)
		{
			out2 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_avg() << endl;
		}
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintDequeMed(T& S)
{
	std::ofstream out1("GalvotukaiDeque0.txt");
	std::ofstream out2("VargsiukaiDeque0.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < studs; i++)
	{
		if (S[i].get_skolaMed() == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_med() << endl;
		}
		else if (S[i].get_skolaMed() == 1)
		{
			out2 <<std::left<<std::setw(20) << S[i].get_name() << std::setw(20) << S[i].get_lastname() << std::setw(20) << std::setprecision(3) <<
			S[i].get_med() << endl;
		}
	}
	out1.close();
	out2.close();
}
template <class G, class B>
void PrintVectorAvg1(G& Good, B& Bad)
{
	std::ofstream out1("GalvotukaiVector1.txt");
	std::ofstream out2("VargsiukaiVector1.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < Good.size(); i++)
	{
        out1 <<std::left<<std::setw(20) << Good[i].get_name() << std::setw(20) << Good[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Good[i].get_avg() << endl;
    }
    for (int i = 0; i < Bad.size(); i++)
    {
		out2 <<std::left<< std::setw(20) <<Bad[i].get_name() << std::setw(20) << Bad[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Bad[i].get_avg() << endl;
	}
	out1.close();
	out2.close();
}
template <class G, class B>
void PrintVectorMed1(G& Good, B& Bad)
{
	std::ofstream out1("GalvotukaiVector1.txt");
	std::ofstream out2("VargsiukaiVector1.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < Good.size(); i++)
	{
        out1 <<std::left<<std::setw(20) << Good[i].get_name() << std::setw(20) << Good[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Good[i].get_med() << endl;
    }
    for (int i = 0; i < Bad.size(); i++)
    {
		out2 <<std::left<< std::setw(20) <<Bad[i].get_name() << std::setw(20) << Bad[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Bad[i].get_med() << endl;
	}
	out1.close();
	out2.close();
}
template <class G, class B>
void PrintDequeAvg1(G& Good, B& Bad)
{
	std::ofstream out1("GalvotukaiDeque1.txt");
	std::ofstream out2("VargsiukaiDeque1.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < Good.size(); i++)
	{
        out1 <<std::left<<std::setw(20) << Good[i].get_name() << std::setw(20) << Good[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Good[i].get_avg() << endl;
    }
    for (int i = 0; i < Bad.size(); i++)
    {
		out2 <<std::left<< std::setw(20) <<Bad[i].get_name() << std::setw(20) << Bad[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Bad[i].get_avg() << endl;
	}
	out1.close();
	out2.close();
}
template <class G, class B>
void PrintDequeMed1(G& Good, B& Bad)
{
	std::ofstream out1("GalvotukaiDeque1.txt");
	std::ofstream out2("VargsiukaiDeque1.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < Good.size(); i++)
	{
        out1 <<std::left<<std::setw(20) << Good[i].get_name() << std::setw(20) << Good[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Good[i].get_med() << endl;
    }
    for (int i = 0; i < Bad.size(); i++)
    {
		out2 <<std::left<< std::setw(20) <<Bad[i].get_name() << std::setw(20) << Bad[i].get_lastname() << std::setw(20) << std::setprecision(3) << 
        Bad[i].get_med() << endl;
	}
	out1.close();
	out2.close();
}
template <class T, class B>
void PrintVectorAvg2(T& S, B& Bad)
{
	std::ofstream out1("GalvotukaiVector2.txt");
	std::ofstream out2("VargsiukaiVector2.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (auto &a : S)
	{
        if(a.get_med()>= 5.00)
		{
			out1 <<std::left<<std::setw(20) << a.get_name() << std::setw(20) << a.get_lastname() << std::setw(20) << std::setprecision(3) << 
            a.get_avg() << endl;
		}
    }
    for (auto &b : Bad)
    {
		out2 <<std::left<< std::setw(20) <<b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) << 
        b.get_avg() << endl;
	}
	out1.close();
	out2.close();
}
template <class T, class B>
void PrintVectorMed2(T& S, B& Bad)
{
	std::ofstream out1("GalvotukaiVector2.txt");
	std::ofstream out2("VargsiukaiVector2.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (auto &a : S)
	{
        if(a.get_med()>= 5.00)
		{
			out1 <<std::left<<std::setw(20) << a.get_name() << std::setw(20) << a.get_lastname() << std::setw(20) << std::setprecision(3) << 
            a.get_med() << endl;
		}
    }
    for (auto &b : Bad)
    {
		out2 <<std::left<< std::setw(20) <<b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) << 
        b.get_med() << endl;
	}
	out1.close();
	out2.close();
}
template <class T, class B>
void PrintDequeAvg2(T& S, B& Bad)
{
	std::ofstream out1("GalvotukaiDeque2.txt");
	std::ofstream out2("VargsiukaiDeque2.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (auto &a : S)
	{
        if(a.get_med()>= 5.00)
		{
			out1 <<std::left<<std::setw(20) << a.get_name() << std::setw(20) << a.get_lastname() << std::setw(20) << std::setprecision(3) << 
            a.get_avg() << endl;
		}
    }
    for (auto &b : Bad)
    {
		out2 <<std::left<< std::setw(20) <<b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) << 
        b.get_avg() << endl;
	}
	out1.close();
	out2.close();
}
template <class T, class B>
void PrintDequeMed2(T& S, B& Bad)
{
	std::ofstream out1("GalvotukaiDeque2.txt");
	std::ofstream out2("VargsiukaiDeque2.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (auto &a : S)
	{
		if(a.get_med()>= 5.00)
		{
			out1 <<std::left<<std::setw(20) << a.get_name() << std::setw(20) << a.get_lastname() << std::setw(20) << std::setprecision(3) << 
            a.get_med() << endl;
		}
    }
    for (auto &b : Bad)
    {
		out2 <<std::left<< std::setw(20) <<b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) << 
        b.get_med() << endl;
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintListAvg(T& S)
{
	std::ofstream out1("GalvotukaiList0.txt");
    std::ofstream out2("VargsiukaiList0.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
    for(int i=0; i<70; i++)
    {
        out1 << line;
    }
    out1 << endl;
    out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
    for(int i=0; i<70; i++)
    {
        out2 << line;
    }
    out2 << endl;
	for(Studentas student : S)
	{
    	for (int i = 0; i < n; i++)
    	{
    		if (student.get_skolaAvg() == 0)
    		{
                out1 <<std::left<<std::setw(20) << student.get_name() << std::setw(20) << student.get_lastname() << std::setw(20) << std::setprecision(3) <<
    			student.get_avg() << endl;
    		}
    		else if (student.get_skolaAvg() == 1)
	    	{
	    		out2 <<std::left<<std::setw(20) << student.get_name() << std::setw(20) << student.get_lastname() << std::setw(20) << std::setprecision(3) <<
    			student.get_avg() << endl;
	    	}
    	}
	}
	out1.close();
	out2.close();
}
template <class T>
void PrintListMed(T& S)
{
	std::ofstream out1("GalvotukaiList0.txt");
    std::ofstream out2("VargsiukaiList0.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
    for(int i=0; i<70; i++)
    {
        out1 << line;
    }
    out1 << endl;
    out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
    for(int i=0; i<70; i++)
    {
        out2 << line;
    }
    out2 << endl;
	for(Studentas student : S)
	{
    	for (int i = 0; i < n; i++)
    	{
    		if (student.get_skolaMed() == 0)
    		{
                out1 <<std::left<<std::setw(20) << student.get_name() << std::setw(20) << student.get_lastname() << std::setw(20) << std::setprecision(3) <<
    			student.get_med() << endl;
    		}
    		else if (student.get_skolaMed() == 1)
	    	{
	    		out2 <<std::left<<std::setw(20) << student.get_name() << std::setw(20) << student.get_lastname() << std::setw(20) << std::setprecision(3) <<
    			student.get_med() << endl;
	    	}
    	}
	}
	out1.close();
	out2.close();
}
///////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template <class G, class B>
void PrintListAvg1(G& Good, B& Bad)
{
	std::ofstream out1("GalvotukaiList1.txt");
    std::ofstream out2("VargsiukaiList1.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
    for(int i=0; i<70; i++)
    {
        out1 << line;
    }
    out1 << endl;
    out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
    for(int i=0; i<70; i++)
    {
        out2 << line;
    }
    out2 << endl;
	for(Galvocius g : Good)
	{
    	out1 <<std::left<<std::setw(20) << g.get_name() << std::setw(20) << g.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	g.get_avg() << endl;
	}
	for(Vargselis b : Bad)
	{
    	out2 <<std::left<<std::setw(20) << b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	b.get_avg() << endl;
	}
	out1.close();
	out2.close();
}
template <class G, class B>
void PrintListMed1(G& Good, B& Bad)
{
	std::ofstream out1("GalvotukaiList1.txt");
    std::ofstream out2("VargsiukaiList1.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
    for(int i=0; i<70; i++)
    {
        out1 << line;
    }
    out1 << endl;
    out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
    for(int i=0; i<70; i++)
    {
        out2 << line;
    }
    out2 << endl;
	for(Galvocius g : Good)
	{
    	out1 <<std::left<<std::setw(20) << g.get_name() << std::setw(20) << g.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	g.get_med() << endl;
	}
	for(Vargselis b : Bad)
	{
    	out2 <<std::left<<std::setw(20) << b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	b.get_med() << endl;
	}
	out1.close();
	out2.close();
}
///////////////////////////////////////////////////////
//////////////////////////////////////////////////////
template <class T, class B>
void PrintListAvg2(T& S, B& Bad)
{
	std::ofstream out1("GalvotukaiList2.txt");
    std::ofstream out2("VargsiukaiList2.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
    for(int i=0; i<70; i++)
    {
        out1 << line;
    }
    out1 << endl;
    out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
    for(int i=0; i<70; i++)
    {
        out2 << line;
    }
    out2 << endl;
	for(Studentas g:S)
	{
    	out1 <<std::left<<std::setw(20) << g.get_name() << std::setw(20) << g.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	g.get_med() << endl;
	}
	for(Vargselis b : Bad)
	{
    	out2 <<std::left<<std::setw(20) << b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	b.get_med() << endl;
	}
	out1.close();
	out2.close();
}
template <class G, class B>
void PrintListMed2(G& S, B& Bad)
{
	std::ofstream out1("GalvotukaiList2.txt");
    std::ofstream out2("VargsiukaiList2.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
    for(int i=0; i<70; i++)
    {
        out1 << line;
    }
    out1 << endl;
    out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
    for(int i=0; i<70; i++)
    {
        out2 << line;
    }
    out2 << endl;
	for(Studentas g:S)
	{
    	out1 <<std::left<<std::setw(20) << g.get_name() << std::setw(20) << g.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	g.get_med() << endl;
	}
	for(Vargselis b : Bad)
	{
    	out2 <<std::left<<std::setw(20) << b.get_name() << std::setw(20) << b.get_lastname() << std::setw(20) << std::setprecision(3) <<
    	b.get_med() << endl;
	}
	out1.close();
	out2.close();
}

