#ifndef _CARTA_
#define _CARTA_

enum FIGURAS {VACIO, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum PALOS {OROS, COPAS, ESPADAS, BASTOS};

class tCarta{
	public:
		tCarta(PALOS p = OROS, FIGURAS f = AS):palo_(p),fig_(f){};
		PALOS palo() const {return palo_;};
		FIGURAS figura() const {return fig_;};
	private:
		PALOS palo_;
		FIGURAS fig_;
};

#endif