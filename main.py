import streamlit as st

st.title('기초로봇공학개론 수업(2024.05.23)')

# Using the "with" syntax
with st.form(key='my_form'):
	text_input = st.text_input(label='조 번호')
	genre = st.radio("성공 유무",
	    [":rainbow[성공]", "***진행중***", "문제 발생 :movie_camera:"],
	    captions = ["뿌듯", "기다려요", "도와줘요"])
	
	if genre == ":rainbow[Comedy]":
	    st.write("You selected 성공.")
	else:
	    st.write("You didn't select 성공.")
	submit_button = st.form_submit_button(label='Submit')
	
