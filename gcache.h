/* gcache.h -- a general purpose caching mechanism */


/* types used throughout */
typedef u_short	tcelen;		/* length of a cached entry		*/
typedef u_short	tceix;		/* index of a cached entry		*/
typedef u_int	thval;		/* type of the hashed value of a key	*/
typedef u_int	ttstamp;	/* type of a timestamp			*/


/* configuration constants */
#define CA_MAXENTRIES	255	/* max entries in a single cache	*/
#define CA_MAXKEY	500	/* max size of a key			*/
#define CA_MAXRES	500	/* max size of a result			*/
#define CA_NAMELEN	15	/* max length of the name of a cache	*/
#define CA_NUMCACHES	10	/* max caches in the system		*/

#define BADCID -1

#define ISBADCACHE(cid) ((cid < 0) || (cid > CA_NUMCACHES))

/* definition of the interface routines */
extern int	cacreate ( /*"name",nentries,lifetime*/	);
extern int	cadestroy( /*CACHEID*/ );
extern int	cainsert ( /*CACHEID,pkey,keylen,pres,preslen*/ );
extern int	calookup ( /*CACHEID,pkey,keylen,pres,preslen*/ );
extern int	capurge  ( /*CACHEID*/ );
extern int	caremove ( /*CACHEID,pkey,keylen*/ );


/* system routines */
extern void	cadump();
extern int	cainit();
