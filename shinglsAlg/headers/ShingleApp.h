#pragma once

#include "../src/gsoap_autogenerated/soapShingleservice.h"
#include "../headers/shingles.h"
#include "../headers/ShingleAppLogger.h"


using namespace std;
/*
main class. It provides receiving massages and its processing
*/
namespace DePlaguarism{
	struct Pair{
		unsigned int docId;
		float similarity;
		Pair (unsigned int _docId, float _similarity){
			docId = _docId;
			similarity = _similarity;
		}
	};

	bool operator==(const Pair & left, const Pair & right);

	struct ClassComp {
		bool operator() (const Pair & left, const Pair & right) const;
	};

	class ShingleApp :
		public shingleService
	{
	protected:
		void initTextById(unsigned int id, t__text * trgt);
		ClassComp objectcomp;
		DbEnv * env; ///< database in BDB
		Db * hashes, ///< bdb table, contains pairs hash => doc_id
			* docs;	///< bdb table, contains pairs doc_id => documentInfo
		vector<Pair> appResult;
		void findSimilar(t__text & txt);  ///<function compares new text with others already in the base
		ShingleAppLogger Log;  ///<logger object. Sends messages in several streams
		int shingleAlgorithm(t__text txt, t__result *res); ///< compare two texts using algorithm based on shingles
		int documentCount;
	public:
		string nowToStr(); ///< converts current date/time to string
		string ipToStr(); ///< converts current client`s ip to string
		ShingleAppLogger & log();  ///<getter for Log field
		ShingleApp();
		~ShingleApp();
		virtual	int CompareText(t__text txt, t__result *res);  ///<main method which process incoming request
	};

}