#include "Button.h"

Boton::Boton(sf::Font& fuente, const sf::Vector2f tamaño)
: m_sobreBotonActivo(true)	//el cursor no esta en el boton
, m_botonPresionado(false)	//el boton no esta presionado
{
	setTamaño(tamaño);	//establece el tamaño del boton con los valores constantes del vector
	setFuente(fuente);	//le da una fuente para las letras
}

void Boton::setTamaño(const sf::Vector2f tam)
{
	b_tamaño = tam;	//el tamaño del boton esta guardado en una variable del mismo tippo
	b_cuerpo.setSize(b_tamaño);	// Establece el tamñano del boton con estos parametros
	actualizar();	// Actualiza los nuevos datos en la pantalla
}

void Boton::setFuente(sf::Font &fuent)
{
	m_fuente = &fuent;	// la fuente es guardada localmente
	m_texto.setFont(*m_fuente); // Establece la fuente del texto
	actualizar();	// Actualiza los datos
}

void Boton::setCadena_Texto(const std::string cadena)
{
	m_texto.setString(cadena);	// Establece la cadena de texto a usar
	actualizar();	// Actualiza los datos
}

void Boton::setColor_Fondo(const NormalBotonColor &NB_color)
{
	b_ColorFondo = NB_color;	// Guarda el color en el una variable
	b_cuerpo.setFillColor(NB_color);	// Establece el color del fondo
}

void Boton::setColor_Texto(const NormalBotonColor &NB_color)
{
	b_ColorTexto = NB_color;	// Guarda el color del texto
	m_texto.setColor(NB_color);		//	Establece el color del Texto
}

void Boton::setColor_Borde(const NormalBotonColor &NB_color)
{
	b_ColorBorde = NB_color;	// Guarda el color del borde
	b_cuerpo.setOutlineColor(NB_color);
}

void Boton::setAncho_Borde(float espesor)
{
	b_cuerpo.setOutlineThickness(espesor);	// Establece el ancho de borde
}

void Boton::setAccionSobreBot(bool activo)
{
	m_sobreBotonActivo = activo;	// Establece si el boton esta activo 
}

void Boton::setColor_FondoRatonSobreBoton(const SobreBotonColor &RSB_color)
{
	sobreB_ColorFondo = RSB_color;
}

void Boton::setColor_TextoRSB(const SobreBotonColor &RSB_color)
{
	sobreB_ColorTexto = RSB_color;
}

void Boton::setColor_BordeRSB(const SobreBotonColor &RSB_color)
{
	sobreB_ColorBorde = RSB_color;
}

void Boton::manejadorE(sf::RenderWindow &ventana)	//Este manejador solo detecta cuando el puntero esta sobre un boton y da el efecto correspondiente
{
	m_mouseEncimaBoton = false;	//no esta
	sf::FloatRect CuerpoRect(getPosition().x, getPosition().y, b_tamaño.x, b_tamaño.y);	//crea el rectangulo que cubre a el boton

	if (CuerpoRect.contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))	// Verifica si el boton contiene la posicion del mouse
	{
		m_mouseEncimaBoton = true;	//si esta
		if (m_sobreBotonActivo)
		{
			m_texto.setColor(sobreB_ColorTexto);	//cambia los parametros a sus valores cuando el boton esta siendo pasado por el mouse
			b_cuerpo.setFillColor(sobreB_ColorFondo);
			b_cuerpo.setOutlineColor(sobreB_ColorBorde);
		}
	}

	else if (m_texto.getColor() != b_ColorTexto)	// si el puntero ya no esta en el boton, entonces debemos cambiar los valores a los normales
	{
		m_texto.setColor(b_ColorTexto);	
		b_cuerpo.setFillColor(b_ColorFondo);
		b_cuerpo.setOutlineColor(b_ColorBorde);
	}
}

void Boton::eventos(sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed && m_mouseEncimaBoton)	//si se hace click cuando el cursor esta sobre el boton entonces se activa
	{
		m_botonPresionado = true;	// el boton es clickeado
	}
	else if (m_botonPresionado && event.type == sf::Event::MouseButtonReleased)	//Cuando el boton ya ha sido clickeado una vez y es liberado recien
	{
		m_botonPresionado = false;	// El boton ya no esta presionado mas
		if (m_mouseEncimaBoton && m_FuncionDesencadenante != nullptr)	// Si el mouse seguia sobre el boton cuando fue liberado y el boton tiene una funcion
		{
			m_FuncionDesencadenante();	// llama a la funcion
		}
	}
}

void Boton::setFuncion(funcion FuncionActual)
{
	m_FuncionDesencadenante = FuncionActual;
}

void Boton::actualizar()	// actualiza el tamaño y letras del boton
{
	if (b_tamaño.x > 0 && b_tamaño.y > 0 && m_texto.getString() != "")	//Si el ancho y alto del boton es mayor que 0 y no tiene ningun texto dentro
	{
		if (m_texto.getGlobalBounds().width < b_tamaño.x / 4 * 3 && m_texto.getGlobalBounds().height < b_tamaño.y - 10.f) //Si el ancho del texto es menor que 3/4 del ancho del boton y el alto del texto es < q el alto del boton -10

		{
			while (m_texto.getGlobalBounds().width < b_tamaño.x / 4 * 3 && m_texto.getGlobalBounds().height < b_tamaño.y - 10.f)	//mientras que el ancho del texto no sea al menos 3/4 del boton y el alto al menos -10 del alto del boton 
			{
				m_texto.setCharacterSize(m_texto.getCharacterSize() + 1);// Aumenta el tamaño de los caracteres en 1
				std::cout << "Entre al while" << std::endl;
			}
			if (m_texto.getGlobalBounds().width < b_tamaño.x / 4 * 3 || m_texto.getGlobalBounds().height < b_tamaño.y - 10.f)	// Si uno de los dos se pasa disminuye el tamaño en 1
			{
				m_texto.setCharacterSize(m_texto.getCharacterSize() - 1);
			}
		}
		else
		{
			while (m_texto.getGlobalBounds().width >b_tamaño.x / 4 * 3 || m_texto.getGlobalBounds().height > b_tamaño.y - 10.f)	// Lo contrario al otro si es muy grande disminuye hasta que sea < 3/4
			{
				m_texto.setCharacterSize(m_texto.getCharacterSize() - 1);
			}
			if (m_texto.getGlobalBounds().width > b_tamaño.x / 4 * 3 || m_texto.getGlobalBounds().height > b_tamaño.y - 10.f) // si disminuye mucho aumenta en 1
			{
				m_texto.setCharacterSize(m_texto.getCharacterSize() + 1);
			}
		}

		m_texto.setOrigin(m_texto.getLocalBounds().left + m_texto.getLocalBounds().width / 2, m_texto.getLocalBounds().top + m_texto.getLocalBounds().height / 2); //Establece el origen del texto en el centro del rectangulo del texto
		m_texto.setPosition(b_tamaño.x / 2, b_tamaño.y / 2); //establece la posicion del boton en el centro del boton
	}
}

void Boton::draw(sf::RenderTarget& seleccionado, sf::RenderStates estados) const
{
	estados.transform *= getTransform();	//Obtiene las transformaciones que se hizo al objeto
	seleccionado.draw(b_cuerpo, estados);	// Dibuja el boton con su estado actual
	seleccionado.draw(m_texto, estados);	// Dibuja el texto del boton
}