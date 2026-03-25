# PROYECTO-INFORMATICA-2
GITHUB PARA EL PROYECTO DE INFORMATICA DE 2DO AÑO
# POR QUÉ ESTE TEMA

Este proyecto se seleccionó debido a la alta mortalidad de peces en acuarios domésticos, causada principalmente por un control deficiente de variables como el pH y la temperatura del agua. Muchas especies de peces son muy sensibles a estos cambios, y la falta de un monitoreo constante afecta su calidad de vida.
slides/03-problema-principal.md
markdown
# PROBLEMA PRINCIPAL

El acuario inteligente está diseñado para mantener la temperatura ideal para los peces, que generalmente oscila entre 24 y 27 °C. Los cambios bruscos de temperatura pueden causarles estrés y enfermedades, por lo que el sistema utiliza Arduino, sensores y un termostato para regular automáticamente el calentador y garantizar un entorno estable y seguro dentro del acuario.
slides/04-sensores.md
markdown
# SENSORES

- **pH:** Permite medir el nivel de acidez del agua en tiempo real, asegurando que se mantenga dentro de los rangos adecuados para la vida de los peces.
- **Temperatura:** Se utiliza para monitorear continuamente las variaciones térmicas del agua, ya que es un factor crítico para el bienestar de las especies acuáticas.
- **Termostato:** Actúa como un sistema de control, permitiendo regular automáticamente la temperatura cuando se detectan desviaciones, garantizando así la estabilidad del entorno.
- **Placa ESP32:** Es la unidad central de procesamiento debido a su capacidad de integrarse con múltiples sensores, su bajo consumo de energía y su conectividad.
Notas del presentador
Guarda en notes/ un archivo por diapositiva con puntos clave y tiempo estimado.

Resumen: Proyecto para diseñar un acuario 100% autónomo que mantiene condiciones óptimas para peces domésticos mediante sensores, una placa ESP32, control de temperatura y una interfaz de monitorización.

# Introducción
El proyecto: Acuario inteligente basado en el Internet de las Cosas (IoT).
El problema: Inestabilidad del ecosistema acuático debido a errores humanos en la supervisión manual.
La solución: Un entorno 100% autónomo; la programación como puente entre el mundo físico y el digital.
Tecnologías integradas: sensores físicos; interfaz de monitorización web; algoritmos de inteligencia artificial.

Imagen sugerida: foto del acuario y/o persona usando laptop y smartphone (colocar en la parte superior derecha).

# Por qué este tema
Este proyecto se seleccionó debido a la alta mortalidad de peces en acuarios domésticos, causada principalmente por un control deficiente de variables como el pH y la temperatura del agua. Muchas especies de peces son muy sensibles a estos cambios, y la falta de un monitoreo constante afecta su calidad de vida.

# Puntos clave:

Alta mortalidad en acuarios domésticos.

Variables críticas: pH y temperatura.

Necesidad de monitoreo continuo y automatizado.

Imagen sugerida: foto de investigación/planning y foto de un acuario doméstico.

# Problema principal
El acuario inteligente está diseñado para mantener la temperatura ideal para los peces, que generalmente oscila entre 24 °C y 27 °C. Los cambios bruscos de temperatura pueden causar estrés y enfermedades. El sistema utiliza Arduino/ESP32, sensores y un termostato para regular automáticamente el calentador y garantizar un entorno estable y seguro.

Consecuencias de no controlar la temperatura:

Estrés en los peces.

Mayor susceptibilidad a enfermedades.

Mortalidad elevada.

# Sensores y componentes
pH  
Permite medir el nivel de acidez del agua en tiempo real, asegurando que se mantenga dentro de los rangos adecuados para la vida de los peces.

Temperatura  
Monitorea continuamente las variaciones térmicas del agua; es un factor crítico para el bienestar de las especies acuáticas.

Termostato  
Actúa como sistema de control para regular automáticamente la temperatura cuando se detectan desviaciones.

Placa ESP32  
Unidad central de procesamiento por su capacidad de integrarse con múltiples sensores, bajo consumo y conectividad Wi‑Fi.

# Lista de componentes sugeridos:

Sensor de pH (electrodo + módulo).

Sensor de temperatura (DS18B20 o similar).

Relé o controlador para el calentador.

Termostato o controlador PID.

Placa ESP32.

Fuente de alimentación estable.

Cables, conectores y carcasa protectora.

# Tecnologías integradas
Hardware: ESP32, sensores de pH y temperatura, relés, calentador controlable.
Software: Firmware en C/C++ para ESP32; lógica de control (umbral, histéresis o PID); registro de datos.
Interfaz: Panel web para monitorización en tiempo real y alertas.
Inteligencia artificial (opcional): algoritmos para detección de patrones, predicción de anomalías y optimización de parámetros.

Flujo básico del sistema:

Lectura de sensores.

Evaluación de condiciones frente a umbrales.

Actuación sobre el calentador mediante relé/termóstato.

Registro y visualización en la interfaz web.

Notificaciones si se detectan anomalías.

# Conclusión
Un acuario inteligente reduce la intervención humana y minimiza errores de supervisión, mejorando la supervivencia y el bienestar de los peces. La combinación de sensores, una placa ESP32 y una interfaz de monitorización permite un control continuo y escalable del ecosistema acuático.
