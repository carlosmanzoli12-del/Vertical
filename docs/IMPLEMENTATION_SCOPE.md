# StreamForge — escopo de implementação

O desenvolvimento foi priorizado exclusivamente nestes blocos:

1. **Integração nativa com OBS Studio 30.0.2**
   - Módulo nativo carregável pelo OBS.
   - Uso da Frontend API oficial.
   - Dock Qt incorporado à interface do OBS.
2. **Multistream**
   - Gerenciador de saídas independentes.
   - Configuração separada por plataforma.
   - Estados, início/parada e tratamento de falhas por destino.
3. **Login/OAuth**
   - Fluxos oficiais de autorização.
   - Tokens protegidos pelo armazenamento seguro do sistema operacional.
   - Nenhuma chave ou segredo no repositório.
4. **Interface visual**
   - Dock StreamForge próprio.
   - Controles de contas, destinos e transmissões.
   - Sem substituir nem alterar os painéis nativos do OBS.

Chat unificado, alertas e overlays ficam fora do escopo atual.

## Requisitos de compilação

A compilação do módulo exige libobs, obs-frontend-api e Qt 6 compatíveis com a instalação alvo do OBS 30.0.2. O alvo nativo fica opcional para permitir que os testes portáteis do núcleo continuem funcionando em ambientes sem o SDK do OBS.

## Estado real

O módulo/dock é um primeiro esqueleto de integração. Os botões de conexão e multistream permanecem sem backend até que os fluxos OAuth e o gerenciador de saídas sejam implementados e testados. Não é ainda uma versão instalável ou funcional de multistream.
