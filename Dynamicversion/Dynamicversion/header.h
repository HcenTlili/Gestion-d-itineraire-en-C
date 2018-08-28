#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAXNODES 50
#define N 20
#define INFINITY 5000
struct ville{
char nomville[50];
int alias;
struct ville* suivant;
};

struct route{
int distance;
char villedepart[50];
char villearrivee[50];
int id;
struct route* suivant;
};
char* aliasfinder(int i,struct ville* K);
void Display_Result(int s,int d,int final,int precede[],int distance[],int weight[][MAXNODES],struct ville* K);
int fctdistance(struct route* L,char a[],char b[]);
struct ville* chargervilles(struct ville*L);
struct route* chargerroutes(struct route*L);
void enregistrer(struct ville* L,struct route* K);
int calculerdistance(struct route* L,char a[],char b[]);
void chercherpcourtchemin(struct route* L);
void chercherpcc(struct route* L);
void calculeritineraire(struct route* L);
void afficherroute(struct route* L);
struct route* supprimerroute(struct route* L);
struct route* modifierroute(struct route* L);
int verifier(int i,struct route* L);
struct route* ajouterroute(struct route* L);
struct route* gererroutes(struct route* L);

void rechercherville(struct ville* L);
void affichervilles(struct ville* L);
struct ville* supprimerville(struct ville* L);
struct ville* modifierville(struct ville*L);
struct ville* ajouterville(struct ville*L);
struct ville* gerervilles(struct ville* L);

#endif // HEADER_H_INCLUDED
