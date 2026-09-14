import { Terminal } from '@xterm/xterm';
import { FitAddon } from '@xterm/addon-fit';
import { openpty } from 'xterm-pty';
import createMenuModule from './wasm/menu.mjs';

const statusEl = document.getElementById('status')!;

const term = new Terminal({
  cursorBlink: true,
  fontFamily: 'monospace',
  fontSize: 14,
  theme: { background: '#000000', foreground: '#eeeeee' },
});

const fitAddon = new FitAddon();
term.loadAddon(fitAddon);

const { master, slave } = openpty();
term.loadAddon(master);

term.open(document.getElementById('terminal')!);
fitAddon.fit();
window.addEventListener('resize', () => fitAddon.fit());

async function boot() {
  try {
    statusEl.textContent = '';
    await createMenuModule({
      pty: slave,
      locateFile: (path: string) => `/wasm/${path}`,
    });
  } catch (err) {
    statusEl.textContent = 'Error cargando el programa: ' + String(err);
    console.error(err);
  }
}

boot();
