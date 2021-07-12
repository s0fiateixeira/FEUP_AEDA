#include "Gallery.h"
#include <ostream>
#include <algorithm>
using namespace std;

Gallery::Gallery(vector<Paint*> c): catalog(PaintCatalogItem("", "", 0, 0.00)), collection(c) {

}

vector<Paint*> Gallery::getCollection() const {
    return collection;
}

void Gallery::setCollection(vector<Paint*> c) {
    collection = c;
}

priority_queue<ExhibitionItem> Gallery::getPaintsToShow() const {
    return paintsToShow;
}
HashTableAuthorRecord Gallery::getAuthorRecords () const {
    return  authorRecords;
}

void Gallery::addAuthorRecord(AuthorRecord ar) {
    authorRecords.insert(ar);
}

void Gallery::generateCatalog() {
    catalog.makeEmpty();
    for(int i = 0; i < collection.size(); i++) {
        catalog.insert(collection[i]);
    }
}

BST<PaintCatalogItem> Gallery::getCatalog() const {
    return catalog;
}


void Gallery::prepareExhibition() {
    while( !paintsToShow.empty())
        paintsToShow.pop();
    for(int i = 0; i < collection.size(); i++) {
        ExhibitionItem ei(collection[i]);
        paintsToShow.push(ei);
    }
}

//-------------------------------------------------------------------------------

bool organize(PaintCatalogItem p1, PaintCatalogItem p2)
{
    if (p1.getYear() == p2.getYear())
    {
        if (p1.getAuthor() == p2.getAuthor())
        {
            return p1.getTitle() < p2.getTitle();
        } else return p1.getAuthor() < p2.getAuthor();
    } else return p1.getYear() > p2.getYear();
}

vector<Paint*> Gallery::getPaintsBy(string a) const
{
    vector<Paint*> tmp;
    BSTItrIn<PaintCatalogItem> it(catalog);
    for (int i = 0;!it.isAtEnd(); i++)
    {
        if (it.retrieve().getAuthor() == a)
        {
            tmp.push_back(it.retrieve().getPaint());
        }
        it.advance();
    }
    sort(tmp.begin(), tmp.end(), organize);
    return tmp;
}

vector<Paint*> Gallery::getPaintsBetween(int y1, int y2) const {
    vector<Paint*> tmp;
    BSTItrIn<PaintCatalogItem> it(catalog);
    for (int i = 0;!it.isAtEnd(); i++)
    {
        if (it.retrieve().getYear() >= y1 && it.retrieve().getYear() <= y2)
        {
            tmp.push_back(it.retrieve().getPaint());
        }
        it.advance();
    }
    sort(tmp.begin(), tmp.end(), organize);
    return tmp;
}

//TODO
bool Gallery::updateTitle(Paint* p, string tnew)
{
    BSTItrIn<PaintCatalogItem> it(catalog);
    for (int i = 0;!it.isAtEnd(); i++)
    {
        if (it.retrieve() == p)
        {
            Paint p1 = *it.retrieve().getPaint();
            catalog.remove(it.retrieve());
            catalog.insert(PaintCatalogItem(p1.getAuthor(), tnew, p1.getYear(), p1.getPrice()));
            return true;
        }
        it.advance();
    }
    return false;
}


//TODO
int Gallery::recordAvailablePainters()
{ //carrega a tabela de dispersao com AuthorRecords
    for (auto it = collection.begin(); it != collection.end(); it++)
    {
        authorRecords.insert(AuthorRecord((*it)->getAuthor(), getPaintsBy((*it)->getAuthor()).size(), 0));
    }
    return authorRecords.size();
}

//TODO
double Gallery::totalSells() const {
    return 0.0;
}

//TODO
double Gallery::sellPaint(string a, string t) {
    return 0.0;
}

//TODO
vector<Paint*> Gallery::nBestExibition(int n, int maxPerYear) {  //escolhe as N mais caras pinturas, dos anos mais antigos, para realizar uma exposição
    vector<Paint*> tmp;
    return tmp;
}

//TODO
int Gallery::itemExibitionOrder(string a, string t) {
    return 0;
}

