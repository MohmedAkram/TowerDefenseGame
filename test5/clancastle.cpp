#include "clancastle.h"

ClanCastle::ClanCastle() {
    QPixmap clancastle(":/new/prefix1/lasthall.png");
    clancastle =clancastle.scaledToHeight(100);
    clancastle=clancastle.scaledToWidth(100);
    setPixmap(clancastle);
}
int ClanCastle::getcoorx()
{
    return x();
}
int ClanCastle::getcoory()
{
    return y();
}
