# ORSTAC - Open Source Robots and Technical Analyses Community

![ORSTAC Logo](https://orstac.com/wp-content/uploads/2025/01/cropped-cropped-logo-ORSTAC.webp)

*Empowering traders with open-source trading bots for Deriv and Binary platforms, as well as MetaTrader MQL4/5 tools.*

[![GitHub stars](https://img.shields.io/github/stars/alanvito1/ORSTAC)](https://github.com/alanvito1/ORSTAC/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/alanvito1/ORSTAC)](https://github.com/alanvito1/ORSTAC/network)
[![License](https://img.shields.io/github/license/alanvito1/ORSTAC)](https://github.com/alanvito1/ORSTAC/blob/main/LICENSE)

[Leia em Português](https://github.com/alanvito1/ORSTAC/blob/master/README.pt-BR.markdown)

## Table of Contents
- [About ORSTAC](#about-orstac)
- [Get Started](#get-started)
- [Repository Structure](#repository-structure)
- [How to Run Robots (DBot)](#how-to-run-robots-dbot)
- [MetaTrader Tools (MQL4/MQL5)](#metatrader-tools-mql4mql5)
- [Copy Trading](#copy-trading)
- [Resources](#resources)
- [Contributing](#contributing)
- [Risk Warning](#risk-warning)
- [License](#license)
- [Project Status](#project-status)

## About ORSTAC

Welcome to ORSTAC, home to the largest open-source collection of over 4000 trading bot scripts for Deriv and Binary platforms. Our mission is to empower traders with accessible, customizable, and transparent automation tools. Whether you're a coder or a trader, ORSTAC offers strategies, insights, and a vibrant community of 1000+ members on Telegram to fuel your success.

> "Game theory rules everything. Come to the game." — Join us for mutual learning and growth.

## Get Started
Start your trading journey with ORSTAC's free resources:
- 📝 **Register**: Create a Deriv account to access DBot. [Sign Up](https://track.deriv.com/_h1BT0Uryldi34Ib7uprVbWNd7ZgqdRLk/1/)
- 🤖 **Download Bots**: Access our script collection. [Download](https://github.com/alanvito1/ORSTAC/archive/refs/heads/main.zip)
- 💬 **Join Community**: Connect with traders. [Telegram](https://t.me/superbinarybots)
- 💼 **Earn Commissions**: Become a Deriv affiliate. [Partner Program](https://track.deriv.com/_h1BT0Uryldilxv1B6h4gZ2Nd7ZgqdRLk/1/)

*Note: Some links are affiliate links, supporting ORSTAC at no extra cost to you.*

## Repository Structure

This repository is organized into several key areas:

*   **Binary & Dbot Scripts/**: A massive collection of XML scripts for Binary.com and Deriv DBot. These are visual programming blocks for automated trading strategies.
*   **Meta Trader/**: Contains Expert Advisors (EAs), Indicators, and Scripts for MetaTrader 4 (MT4) and MetaTrader 5 (MT5).
    *   `mt4/MQL4/Experts/`: Automated trading robots (e.g., `Moving Average.mq4`, `Konkis_EA_BO_Tester_v3.0.mq4`).
    *   `mt4/MQL4/Indicators/`: Custom indicators for chart analysis.
    *   `mt4/MQL4/Scripts/`: Utility scripts (e.g., `PeriodConverter.mq4` for creating custom timeframes).
*   **Study Materials/**: Educational resources for traders.
*   **Testing and Edit/**: Experimental scripts and bots under development.

## How to Run Robots (DBot)
Follow these steps to use our trading bots on Deriv DBot:
1. **Register on Deriv DBot**  
   Sign up for a free Deriv account to access DBot, a visual platform for building bots. [Create Account | Learn About DBot](https://track.deriv.com/_h1BT0Uryldi34Ib7uprVbWNd7ZgqdRLk/1/)
2. **Download Bots**  
   Get our collection of XML scripts. [Download ZIP](https://github.com/alanvito1/ORSTAC/archive/refs/heads/main.zip)
3. **Load XML in DBot**  
   Upload the XML file to DBot to visualize blocks—no coding required.
4. **Customize Parameters**  
   Adjust settings like stop-loss or trade size to fit your strategy.
5. **Run and Monitor**  
   Click **Run** and track performance on a **DEMO ACCOUNT** first.
6. **Contribute**  
   Share your own scripts or improvements! See [Contributing](#contributing).

📌 **Tip**: Always test bots in a demo account to understand their behavior.

## MetaTrader Tools (MQL4/MQL5)

The repository includes source code for MetaTrader tools, fully documented for ease of understanding and modification.

### Key Files
*   **Konkis_EA_BO_Tester_v3.0.mq4**: A Binary Options tester EA for MT4. It includes features for Martingale strategies, custom indicators, and detailed logging.
*   **Moving Average.mq4**: A standard Moving Average crossover EA.
*   **MACD Sample.mq4**: An EA demonstrating MACD-based trading logic.
*   **PeriodConverter.mq4**: A script to generate non-standard timeframes (e.g., H2, M3) by converting history from standard periods.
*   **DLLSample.cpp**: A C++ example for creating DLLs to extend MetaTrader functionality.

### Usage
To use these files:
1.  Copy the `.mq4` or `.mq5` files to your MetaTrader Data Folder (File -> Open Data Folder -> MQL4/Experts, Indicators, or Scripts).
2.  Open MetaEditor (F4 in MetaTrader) and compile the files.
3.  Drag and drop the compiled tools from the Navigator window onto your chart.

## Copy Trading
Mirror top traders' strategies with Deriv MT5 Signals. Trades are replicated automatically in real-time. [Start Copy Trading](https://track.deriv.com/_h1BT0Uryldj45mrAMZ2h2WNd7ZgqdRLk/1/)

## Resources
Enhance your trading skills with these resources:
| Resource | Description |
|----------|-------------|
| [ORSTAC Blog](https://orstac.com) | Articles on trading strategies and risk management. |
| [GitHub Discussions](https://github.com/alanvito1/ORSTAC/discussions) | Community Q&A and strategy tips. |
| [Deriv DBot Docs](https://deriv.com/dbot) | Official guide to building bots. |
| [Technical Tips](https://orstac.com/category/technical-tips/) | *Thriving in Today's Highly Volatile Market*. |
| [Book Recommendation](https://pay.kiwify.com.br/PHsbGPU) | *Complete Guide: Wisdom Capsules for Traders. |

## Contributing
We welcome contributions from traders and developers! To add a bot script or improve the repository:
1. Fork the repository.
2. Create a branch (`git checkout -b feature/new-bot`).
3. Submit a pull request with your changes.
See our [Contributing Guidelines](CONTRIBUTING.md) and join the discussion on [GitHub](https://github.com/alanvito1/ORSTAC/discussions) or [Telegram](https://t.me/superbinarybots).

## Risk Warning
> **Important**: Trading on Deriv involves complex derivatives like options and CFDs, which carry high risk. You may lose all your capital. Never trade with borrowed funds or money you cannot afford to lose. Always start with a [DEMO ACCOUNT](https://track.deriv.com/_h1BT0Uryldi34Ib7uprVbWNd7ZgqdRLk/1/).

## License
All scripts are licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Project Status
Actively maintained by [Alan Victor](https://github.com/alanvito1) and the ORSTAC community. Issues and pull requests are welcome!

---

Warm regards,  
**Alan Victor**  
Founder & Community Maintainer
