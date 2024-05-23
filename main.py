import streamlit as st

st.title('기초로봇공학개론 수업(2024.05.23)')

# # Using the "with" syntax
# with st.form(key='my_form'):
# 	text_input = st.text_input(label='조 번호')
# 	genre = st.radio("성공 유무",
# 	    [":rainbow[성공]", "***진행중***", "문제 발생 :movie_camera:"],
# 	    captions = ["뿌듯", "기다려주세요", "도와주세요"])
	
# 	submit_button = st.form_submit_button(label='Submit')

# 	if submit_button:


# Initialize connection.
conn = st.connection("postgresql", type="sql")

# Perform query.
df = conn.query('SELECT * FROM mytable;', ttl="10m")

# Print results.
for row in df.itertuples():
    st.write(f"{row.name} has a :{row.pet}:")
	
