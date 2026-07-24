# Batalha Naval em C

Programa em C que simula um jogo de Batalha Naval no terminal usando matrizes bidimensionais.

## Funcionalidades do Código

- **Tabuleiro 10x10:** Representação do campo via matriz inteira.
- **Validação de Posição:** Valida se navios verticais, horizontais ou diagonais ultrapassam os limites da matriz antes de inserir.
- **Habilidades de Área:** Lógica para aplicar padrões geométricos de ataque (Cone, Cruz e Octaedro) e alterar o estado do tabuleiro.
- **Tratamento de Estado:** Diferenciação entre água, navios e locais atingidos.

## Representação da Matriz

- `0` - Água
- `3` - Navio posicionado
- `5` - Habilidade aplicada em água
- `1` - Habilidade aplicada sobre um navio

