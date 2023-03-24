defmodule InClass.Repo.Migrations.CreateGeneralareas do
  use Ecto.Migration

  def change do
    create table(:generalareas) do
      add :name, :string

      timestamps()
    end
  end
end
