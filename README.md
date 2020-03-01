[TOC]

# C++ HTTP Mock

C++ HTTP Mock (chttpm) was born out of the need of making quick-and-dirty mocks of REST Web Services to aid with software testing. This is a small utility project with the aim of making HTTP servers with hard coded behavior easier.

## When to use

- A mock to a web service is needed over HTTP (as in not hard-wired stub in a project code);
- Dumb answers over simple logic is enough to be useful;
- You don't know, or cannot use, or do not want to use other fast solutions involving as-fast means such as Python or Go;
- You like Angelscript.

## When to NOT use

- You need more than dumb or stub answers. In this case, you're more likely better out making your own mock from scratch. Many languages and libraries can make this reasonably painless;
- Mock performance is a must;
- You intend of making a real application.

# Dependencies

This project has the following dependencies:

- `Cpp HTTPLib`: simple header only HTTP Library to act as the HTTP Server.
- `Angel Script`: scripting language to allow to change the HTTP Server behavior without recompiling the source.

The dependencies are included in the source code and compiled together with CHTTPM. See their respective folders for information about their licenses.

# How to use

You don't. The project is still in a too early of an state to be useful

# Compiling

TODO : write this

# Why no automated tests (yet)

Most of the source code involves either Cpp HTTPLib or Angel Script. I'm trying to figure out how to best write automated tests that work with them. Some refactors may be needed when I get it.

# License

CHTTPM is licensed under the `BSD 3-Clause License` license. See `src/chttpm/LICENSE` file for more information.