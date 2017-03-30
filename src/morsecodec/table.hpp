/*
 * qCw
 * Copyright (C) 2017  Luca Cireddu
 * sardylan@gmail.com
 * http://www.lucacireddu.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __QCW_MORSECODEC_TABLE_H
#define __QCW_MORSECODEC_TABLE_H

#include <QHash>
#include <QString>
#include <QList>

#define DOT 1
#define DASH 3


static QHash<QChar, QList<int>> initMorseTable() {
    QHash<QChar, QList<int>> morseTable;

    morseTable.insert('A', {DOT, DASH});
    morseTable.insert('B', {DASH, DOT, DOT, DOT});
    morseTable.insert('C', {DASH, DOT, DASH, DOT});
    morseTable.insert('D', {DASH, DOT, DOT});
    morseTable.insert('E', {DOT});
    morseTable.insert('F', {DOT, DOT, DASH, DOT});
    morseTable.insert('G', {DASH, DASH, DOT});
    morseTable.insert('H', {DOT, DOT, DOT, DOT});
    morseTable.insert('I', {DOT, DOT});
    morseTable.insert('J', {DOT, DASH, DASH, DASH});
    morseTable.insert('K', {DASH, DOT, DASH});
    morseTable.insert('L', {DOT, DASH, DOT, DOT});
    morseTable.insert('M', {DASH, DASH});
    morseTable.insert('N', {DASH, DOT});
    morseTable.insert('O', {DASH, DASH, DASH});
    morseTable.insert('P', {DOT, DASH, DASH, DOT});
    morseTable.insert('Q', {DASH, DASH, DOT, DASH});
    morseTable.insert('R', {DOT, DASH, DOT});
    morseTable.insert('S', {DOT, DOT, DOT});
    morseTable.insert('T', {DASH});
    morseTable.insert('U', {DOT, DOT, DASH});
    morseTable.insert('V', {DOT, DOT, DOT, DASH});
    morseTable.insert('W', {DOT, DASH, DASH});
    morseTable.insert('X', {DASH, DOT, DOT, DASH});
    morseTable.insert('Y', {DASH, DOT, DASH, DASH});
    morseTable.insert('Z', {DASH, DASH, DOT, DOT});

    morseTable.insert('0', {DASH, DASH, DASH, DASH, DASH});
    morseTable.insert('1', {DOT, DASH, DASH, DASH, DASH});
    morseTable.insert('2', {DOT, DOT, DASH, DASH, DASH});
    morseTable.insert('3', {DOT, DOT, DOT, DASH, DASH});
    morseTable.insert('4', {DOT, DOT, DOT, DOT, DASH});
    morseTable.insert('5', {DOT, DOT, DOT, DOT, DOT});
    morseTable.insert('6', {DASH, DOT, DOT, DOT, DOT});
    morseTable.insert('7', {DASH, DASH, DOT, DOT, DOT});
    morseTable.insert('8', {DASH, DASH, DASH, DOT, DOT});
    morseTable.insert('9', {DASH, DASH, DASH, DASH, DOT});

    morseTable.insert('.', {DOT, DASH, DOT, DASH, DOT, DASH});
    morseTable.insert(',', {DASH, DASH, DOT, DOT, DASH, DASH});
    morseTable.insert(':', {DASH, DASH, DASH, DOT, DOT, DOT});
    morseTable.insert('?', {DOT, DOT, DASH, DASH, DOT, DOT});
    morseTable.insert('=', {DASH, DOT, DOT, DOT, DASH});
    morseTable.insert('-', {DASH, DOT, DOT, DOT, DOT, DASH});
    morseTable.insert('(', {DASH, DOT, DASH, DASH, DOT});
    morseTable.insert(')', {DASH, DOT, DASH, DASH, DOT, DASH});
    morseTable.insert('"', {DOT, DASH, DOT, DOT, DASH, DOT});
    morseTable.insert('\'', {DOT, DASH, DASH, DASH, DASH, DOT});
    morseTable.insert('/', {DASH, DOT, DOT, DASH, DOT});
    morseTable.insert('_', {DOT, DOT, DASH, DASH, DOT, DASH});
    morseTable.insert('@', {DOT, DASH, DASH, DOT, DASH, DOT});
    morseTable.insert('!', {DASH, DOT, DASH, DOT, DASH, DASH});

//    morseTable.insert('DOT', {DOT, DASH, DOT, DASH, DOT, DASH});
//    morseTable.insert('COMMA', {DASH, DASH, DOT, DOT, DASH, DASH});
//    morseTable.insert('SEMICOLON', {DASH, DASH, DASH, DOT, DOT, DOT});
//    morseTable.insert('QUESTION', {DOT, DOT, DASH, DASH, DOT, DOT});
//    morseTable.insert('EQUAL', {DASH, DOT, DOT, DOT, DASH});
//    morseTable.insert('DASH', {DASH, DOT, DOT, DOT, DOT, DASH});
//    morseTable.insert('PARENTHESIS_OPEN', {DASH, DOT, DASH, DASH, DOT});
//    morseTable.insert('PARENTHESIS_CLOSE', {DASH, DOT, DASH, DASH, DOT, DASH});
//    morseTable.insert('QUOTE_DOUBLE', {DOT, DASH, DOT, DOT, DASH, DOT});
//    morseTable.insert('QUOTE_SINGLE', {DOT, DASH, DASH, DASH, DASH, DOT});
//    morseTable.insert('STROKE', {DASH, DOT, DOT, DASH, DOT});
//    morseTable.insert('UNDERLINE', {DOT, DOT, DASH, DASH, DOT, DASH});
//    morseTable.insert('AT', {DOT, DASH, DASH, DOT, DASH, DOT});
//    morseTable.insert('EXCLAMATION', {DASH, DOT, DASH, DOT, DASH, DASH});
//
    return morseTable;
}

#endif
