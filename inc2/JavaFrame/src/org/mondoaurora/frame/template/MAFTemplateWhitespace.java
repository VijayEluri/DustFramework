package org.mondoaurora.frame.template;

import org.mondoaurora.frame.shared.*;

public class MAFTemplateWhitespace extends MAFTemplateBase {
	String wsToWrite;
	MAFStream.Out.Indent endLineIndent;
	int blankLines;
	
	public MAFTemplateWhitespace(String ws, MAFStream.Out.Indent endLineIndent, int blank){
		wsToWrite = ws;
		this.endLineIndent = endLineIndent;
		this.blankLines = blank;
	}

	public MAFTemplateWhitespace(){
		this(" ", null, 0);
	}

	public MAFTemplateWhitespace(String ws){
		this(ws, null, 0);
	}

	public MAFTemplateWhitespace(MAFStream.Indent endLineIndent){
		this(null, endLineIndent, 0);
	}

	public MAFTemplateWhitespace(MAFStream.Indent endLineIndent, int elCount){
		this(null, endLineIndent, elCount);
	}

	@Override
	public void writeInto(MAFStream.Out stream, MAFVariant var) {
		if ( null != wsToWrite ) {
			stream.put(wsToWrite);
		}
		if ( null != endLineIndent ) {
			stream.endLine(endLineIndent);
			for ( int i = 0; i < blankLines; ++i ) {
				stream.endLine(MAFStream.Out.Indent.keep);
			}
		}
	}
	
	@Override
	protected Return processChar(char c, Object ctx) {
		return Character.isWhitespace(c) ? CONTINUE : SUCCESS_RETRY;
	}

	@Override
	protected String toStringInt() {
		return "ws";
	}
}
