import { ITerminalAddon, Terminal } from '@xterm/xterm';

declare const enum Flags {
    ISTRIP = 32,
    INLCR = 64,
    IGNCR = 128,
    ICRNL = 256,
    IUCLC = 512,
    IXON = 1024,
    IXANY = 2048,
    IMAXBEL = 8192,
    IUTF8 = 16384,
    OPOST = 1,
    OLCUC = 2,
    ONLCR = 4,
    OCRNL = 8,
    ONOCR = 16,
    ONLRET = 32,
    TABDLY = 6144,
    XTABS = 6144,
    ISIG = 1,
    ICANON = 2,
    ECHO = 8,
    ECHOE = 16,
    ECHOK = 32,
    ECHONL = 64,
    NOFLSH = 128,
    ECHOCTL = 512,
    ECHOPRT = 1024,
    ECHOKE = 2048,
    IEXTEN = 32768,
    VINTR = 0,
    VQUIT = 1,
    VERASE = 2,
    VKILL = 3,
    VEOF = 4,
    VTIME = 5,
    VMIN = 6,
    VSWTCH = 7,
    VSTART = 8,
    VSTOP = 9,
    VSUSP = 10,
    VEOL = 11,
    VREPRINT = 12,
    VDISCARD = 13,
    VWERASE = 14,
    VLNEXT = 15,
    VEOL2 = 16
}
interface TermiosConfig {
    readonly iflag: number;
    readonly oflag: number;
    readonly cflag: number;
    readonly lflag: number;
    readonly cc: ReadonlyArray<number>;
}
declare class Termios implements TermiosConfig {
    readonly iflag: number;
    readonly oflag: number;
    readonly cflag: number;
    readonly lflag: number;
    readonly cc: ReadonlyArray<number>;
    constructor(iflag: number, oflag: number, cflag: number, lflag: number, cc: ReadonlyArray<number>);
    readonly ISTRIP_P: boolean;
    readonly INLCR_P: boolean;
    readonly IGNCR_P: boolean;
    readonly ICRNL_P: boolean;
    readonly IUCLC_P: boolean;
    readonly IXON_P: boolean;
    readonly IXANY_P: boolean;
    readonly IUTF8_P: boolean;
    readonly OPOST_P: boolean;
    readonly OLCUC_P: boolean;
    readonly ONLCR_P: boolean;
    readonly OCRNL_P: boolean;
    readonly ONOCR_P: boolean;
    readonly ONLRET_P: boolean;
    readonly TABDLY_XTABS_P: boolean;
    readonly ISIG_P: boolean;
    readonly ICANON_P: boolean;
    readonly ECHO_P: boolean;
    readonly ECHOE_P: boolean;
    readonly ECHOK_P: boolean;
    readonly ECHONL_P: boolean;
    readonly NOFLSH_P: boolean;
    readonly ECHOCTL_P: boolean;
    readonly ECHOPRT_P: boolean;
    readonly ECHOKE_P: boolean;
    readonly IEXTEN_P: boolean;
    readonly INTR_V: number;
    readonly QUIT_V: number;
    readonly ERASE_V: number;
    readonly KILL_V: number;
    readonly EOF_V: number;
    readonly TIME_V: number;
    readonly MIN_V: number;
    readonly SWTCH_V: number;
    readonly START_V: number;
    readonly STOP_V: number;
    readonly SUSP_V: number;
    readonly EOL_V: number;
    readonly REPRINT_V: number;
    readonly DISCARD_V: number;
    readonly WERASE_V: number;
    readonly LNEXT_V: number;
    readonly EOL2_V: number;
    static fromConfig(config: TermiosConfig): Termios;
    clone(): Termios;
}

declare class LineDiscipline {
    private _onWriteToLower;
    readonly onWriteToLower: (listener: (arg: number[]) => void) => {
        dispose: () => void;
    };
    private _onWriteToUpper;
    readonly onWriteToUpper: (listener: (arg: number[]) => void) => {
        dispose: () => void;
    };
    private _onSignalToUpper;
    readonly onSignalToUpper: (listener: (arg: Signal) => void) => {
        dispose: () => void;
    };
    private _onFlowActivated;
    readonly onFlowActivated: (listener: (arg: void) => void) => {
        dispose: () => void;
    };
    private _onFlowDeactivated;
    readonly onFlowDeactivated: (listener: (arg: void) => void) => {
        dispose: () => void;
    };
    private T;
    private keyActions;
    private flowActivated;
    private column;
    private baseColumn;
    private vlnext;
    private echoprt;
    private toLowerBuf;
    private toUpperBuf;
    constructor();
    private activateFlow;
    private deactivateFlow;
    get flow(): boolean;
    get termios(): Termios;
    set termios(T: Termios);
    private clearToLower;
    private flushToLower;
    private outputToLower;
    private updateBaseColumn;
    private clearToUpper;
    private flushToUpper;
    private outputToUpper;
    private outputToLowerWithPostprocess;
    private echoToLower;
    private inputFromLowerWithPreprocess;
    private erase;
    private startECHOPRT;
    private finishECHOPRT;
    private signal;
    private checkStartFlow;
    private nextLiteral;
    private reprint;
    writeFromLower(arg: number[] | string): void;
    writeFromUpper(arg: number[] | string): void;
}

type Signal = "SIGINT" | "SIGQUIT" | "SIGTSTP" | "SIGWINCH";
declare class Master implements ITerminalAddon {
    private ldisc;
    private slave;
    private disposables;
    private _onWrite;
    readonly onWrite: (listener: (arg: [Uint8Array<ArrayBufferLike>, () => void]) => void) => {
        dispose: () => void;
    };
    private fromLdiscToLowerBuffer;
    private waitingForLower;
    private notifyWritable;
    private notifyResize;
    constructor(ldisc: LineDiscipline, slave: Slave);
    activate(xterm: Terminal): void;
    dispose(): void;
}
declare class Slave {
    private ldisc;
    private _onReadable;
    readonly onReadable: (listener: (arg: void) => void) => {
        dispose: () => void;
    };
    private _onWritable;
    readonly onWritable: (listener: (arg: void) => void) => {
        dispose: () => void;
    };
    private _onSignal;
    readonly onSignal: (listener: (arg: Signal) => void) => {
        dispose: () => void;
    };
    private fromLdiscToUpperBuffer;
    private fromUpperToLdiscBuffer;
    private winsize;
    constructor(ldisc: LineDiscipline);
    initFromMaster(): {
        notifyWritable: () => void;
        notifyResize: (rows: number, cols: number) => void;
    };
    get readable(): boolean;
    read(length?: number): number[];
    get writable(): boolean;
    write(arg: string | number[]): void;
    ioctl(req: "TCGETS"): Termios;
    ioctl(req: "TCSETS", arg: TermiosConfig): void;
    ioctl(req: "TIOCGWINSZ"): [number, number];
}
declare const openpty: () => {
    master: Master;
    slave: Slave;
};

export { Flags, Termios, type TermiosConfig, openpty };
